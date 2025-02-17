import 'dart:async';
import 'dart:convert';
import 'dart:developer';
import 'package:collection/collection.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:web_socket_channel/web_socket_channel.dart';
import '../DataStructures/Pair.dart';
import '../Model/Character.dart';
import 'DatabaseContext.dart';

const String ipAddress = '10.0.2.2';

class ServerSupportCharacterRepository extends ChangeNotifier{
  final String ipAddress = '10.0.2.2';
  WebSocketChannel? _channel;
  bool _online = false;
  bool _isReconnecting = false;
  bool get isOnline => _online;

  Function(bool)? onOnlineStatusChanged;
  Function(bool)? onDataUpdated;

  List<Character> _characters;
  List<Character> _addedDbCharacters = [];
  List<Character> _deletedDbCharacters = [];
  List<Character> _updatedDbCharacters = [];

  late StreamSubscription _streamSubscription;

  final DatabaseContext _dbContext = DatabaseContext.instance;

  ServerSupportCharacterRepository(this._characters) {
    _initializeWebSocket();
    _monitorOnlineStatus();
  }

  static Future<ServerSupportCharacterRepository> init() async {
    final dbCharacters = await DatabaseContext.instance.getAllCharacters();
    final repository = ServerSupportCharacterRepository(dbCharacters);
    return repository;
  }

  Future<void> _initializeWebSocket() async {
    if (_channel != null) {
      log('WebSocket already initialized.');
      return;
    }

    try {
      _channel = WebSocketChannel.connect(Uri.parse("ws://$ipAddress:8080/ws"));
      _streamSubscription = _channel!.stream.listen(
            (data) => _handleServerMessage(data),
        onDone: _reconnect,
        onError: (error) => log('WebSocket error: $error'),
      );
    } catch (e) {
      log('Failed to initialize WebSocket: $e');
    }
  }

  Future<void> _reconnect() async {
    log('Attempting WebSocket reconnection...');

    if (_isReconnecting) {
      log('Already reconnecting, skipping this attempt');
      return;
    }

    _isReconnecting = true;

    await _streamSubscription.cancel();
    _channel?.sink.close();
    await _initializeWebSocket();

    _isReconnecting = false;
  }

  Future<void> _handleServerMessage(String data) async {
    try {
      var listData = data.split('\$');
      log("Received server message to sync");
      switch (listData[0]) {
        case "ADD":
          var character = Character.fromJson(jsonDecode(listData[1]));
          log("Added $character");
          await _dbContext.insertCharacter(character);
          break;
        case "UPDATE":
          var character = Character.fromJson(jsonDecode(listData[1]));
          log("Updated $character");
          await updateLocally(character.characterId, character);
          break;
        case "DELETE":
          log("Deleted entity");
          await removeLocally(listData[1]);
          break;
      }
      onDataUpdated?.call(true);
    } catch (e) {
      log('Error handling server message: $e');
    }
  }

  Future<void> _synchronizeServerAndClients() async {
    if (!_online) return;

    try {
      List<Character> locallyAddedCharacters = [];
      final allLocalCharacters = await _dbContext.getAllCharacters();

      for (var character in allLocalCharacters) {
        if (!_characters.any((serverCharacter) => serverCharacter.characterId == character.characterId)) {
          locallyAddedCharacters.add(character);
        }
      }

      var syncPayload = {
        'newCharacters': _addedDbCharacters.map((c) => c.toJson()).toList(),
        'deletedIds': _deletedDbCharacters.map((c) => c.characterId).toList(),
        'updatedCharacters': _updatedDbCharacters.map((c) => c.toJson()).toList(),
      };

      var body = jsonEncode(syncPayload);
      var response = await http.post(
        Uri.parse("http://$ipAddress:8080/characters/sync"),
        headers: {
          'Content-Type': 'application/json',
        },
        body: body,
      );

      if (response.statusCode == 200) {
        var result = jsonDecode(response.body);
        List<Character> serverCharacters = [];

        if (result is List) {
          serverCharacters = result
              .map((json) => Character.fromJson(json as Map<String, dynamic>))
              .toList();
        }

        for (var localCharacter in _characters) {
          if (!serverCharacters.any((e) => e.characterId == localCharacter.characterId)) {
            serverCharacters.add(localCharacter);
          }
        }

        for (var serverCharacter in serverCharacters) {
          Character? localCharacter = _characters.firstWhereOrNull(
                (e) => e.characterId == serverCharacter.characterId,
          );

          if (localCharacter == null) {
            _dbContext.insertCharacter(serverCharacter);
          } else {
            _dbContext.updateCharacter(serverCharacter);
          }
        }

        for (var localCharacter in _characters) {
          if (!serverCharacters.any((e) => e.characterId == localCharacter.characterId)) {
            _dbContext.deleteCharacter(localCharacter.characterId);
          }
        }

      _addedDbCharacters.clear();
      _deletedDbCharacters.clear();
      _updatedDbCharacters.clear();

      notifyDataChanged();
      }
    } catch (e) {
      log('Error during synchronization: $e');
    }
  }

  void notifyDataChanged() {
    notifyListeners();
  }

  Future<void> _monitorOnlineStatus() async {
    while (true) {
      await Future.delayed(const Duration(seconds: 5));
      bool previousStatus = _online;
      try {
        var response = await http.get(Uri.parse("http://$ipAddress:8080/characters/")).timeout(const Duration(seconds: 5));
        _online = response.statusCode == 200;
      } catch (_) {
        _online = false;
      }
      if (_online != previousStatus) {
        onOnlineStatusChanged?.call(_online);
        if (_online) {
          await _initializeWebSocket();
          await _synchronizeServerAndClients();
        }
      }
    }
  }

  Future<Pair> getAll() async {
    if (_online) {
      try {
        var response = await http.get(Uri.parse("http://$ipAddress:8080/characters"));
        if (response.statusCode == 200) {
          var res = jsonDecode(response.body);
          var charactersJson = res['characters'] as List;
          _characters
            ..clear()
            ..addAll(charactersJson.map((json) => Character.fromJson(json)));
          return Pair(_characters, _online);
        }
      } catch (e) {
        log('Error fetching from server: $e');
      }
    }
    return getLocally();
  }

  Future<Pair> getLocally() async {
    _characters
      ..clear()
      ..addAll(await _dbContext.getAllCharacters());
    return Pair(_characters, _online);
  }

  Future<void> add(Character character) async {
    if (_online) {
      try {
        var response = await http.post(
          Uri.parse("http://$ipAddress:8080/characters"),
          headers: {'Content-Type': 'application/json'},
          body: jsonEncode(character.toJson()),
        );
        if (response.statusCode == 200) {
          await _dbContext.insertCharacter(character);
          return;
        }
      } catch (e) {
        _addedDbCharacters.add(character);
        log('Error adding character: $e');
      }
    } else {
      _addedDbCharacters.add(character);
      _dbContext.insertCharacter(character);
    }
  }

  Future<void> remove(String id) async {
    if (_online) {
      try {
        var response = await http.delete(Uri.parse("http://$ipAddress:8080/characters/$id"));
        if (response.statusCode == 200) {
          await removeLocally(id);
          return;
        }
      } catch (e) {
        _deletedDbCharacters.add(_characters.firstWhere(
                (element) => element.characterId == id));
        log('Error removing character: $e');
      }
    } else {
      _deletedDbCharacters.add(_characters.firstWhere(
              (element) => element.characterId == id));
      await removeLocally(id);
    }
  }

  Future<void> update(String id, Character character) async {
    if (_online) {
      try {
        var response = await http.put(
          Uri.parse("http://$ipAddress:8080/characters"),
          headers: {'Content-Type': 'application/json'},
          body: jsonEncode(character.toJson()),
        );
        if (response.statusCode == 200) {
          await updateLocally(id, character);
          return;
        }
      } catch (e) {
        _updatedDbCharacters.add(character);
        log('Error updating character: $e');
      }
    } else {
      _updatedDbCharacters.add(character);
      await updateLocally(id, character);
    }
  }

  Future<void> removeLocally(String id) async {
    _characters.removeWhere((c) => c.characterId == id);
    _dbContext.deleteCharacter(id);
  }

  Future<void> updateLocally(String id, Character character) async {
    await _dbContext.updateCharacter(character);
  }

  void dispose() {
    _streamSubscription.cancel();
    _channel?.sink.close();
  }
}
