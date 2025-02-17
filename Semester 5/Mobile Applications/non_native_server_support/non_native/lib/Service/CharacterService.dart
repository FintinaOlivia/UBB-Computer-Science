import 'package:flutter/material.dart';
import 'package:non_native/Model/Character.dart';
import '../DataStructures/Pair.dart';

import '../Repository/DatabaseContext.dart';
import '../Repository/ServerSupport_CharacterRepository.dart';

class CharactersService extends ChangeNotifier {
  final ServerSupportCharacterRepository _repository;

  CharactersService(this._repository) {
    _repository.addListener(_onRepositoryChange);
    _repository.onOnlineStatusChanged = (isOnline) {
      notifyListeners();
    };
    _repository.onDataUpdated = (is_updated) {
      notifyListeners();
    };
  }

  bool get is_online => _repository.isOnline;

  static Future<CharactersService> init() async {
    var repository = await ServerSupportCharacterRepository.init();
    return CharactersService(repository);
  }

  void _onRepositoryChange() {
    notifyListeners();
  }

  Future<bool> addCharacter(
      String characterId,
      String name,
      String story,
      String description,
      String age,
      String background,
      String skills,
      String strengths,
      String weaknesses,
      String notableFeatures,
      bool isFavourite,
      ) async {
    final character = Character(
      characterId: characterId,
      name: name,
      story: story,
      description: description,
      age: age,
      background: background,
      skills: skills,
      strengths: strengths,
      weaknesses: weaknesses,
      notableFeatures: notableFeatures,
      isFavourite: isFavourite,
    );

    await _repository.add(character).then((_) {
      notifyListeners();
    });
    return true;
  }

  void addCharacterFromObject(Character character) {
    _repository.add(character).then((_) {
      notifyListeners();
    });
  }

  Future<bool> removeCharacter(String characterId) async {
    await _repository.remove(characterId).then((_) {
      notifyListeners();
    });
    return true;
  }

  Future<bool> updateCharacter(
      String characterId,
      String name,
      String story,
      String description,
      String age,
      String background,
      String skills,
      String strengths,
      String weaknesses,
      String notableFeatures
      ) async {
    final updatedCharacter = Character(
      characterId: characterId,
      name: name,
      story: story,
      description: description,
      age: age,
      background: background,
      skills: skills,
      strengths: strengths,
      weaknesses: weaknesses,
      notableFeatures: notableFeatures
    );

    await _repository.update(characterId, updatedCharacter).then((_) {
      notifyListeners();
    });

    return true;
  }

  void updateCharacterByObject(Character updatedCharacter) {
    _repository.update(updatedCharacter.characterId, updatedCharacter).then((_) {
      notifyListeners();
    });
  }

  Future<Pair> getAllCharacters(bool initLocally) async {
    if(initLocally){
      return await _repository.getLocally();
    }
    return await _repository.getAll();
  }
}
