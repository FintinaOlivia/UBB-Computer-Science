import 'dart:async';
import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import 'package:uuid/uuid.dart';

import '../Model/Character.dart';

class DatabaseContext {
  static Database? _database;

  DatabaseContext._privateConstructor();
  static final DatabaseContext instance = DatabaseContext._privateConstructor();

  Future<Database> get database async {
    if (_database != null) {
      return _database!;
    }

    _database = await _initDatabase();
    return _database!;
  }

  Future<Database> _initDatabase() async {
    String databasePath = await getDatabasesPath();
    String path = join(databasePath, 'characters-server.db');

    return await openDatabase(path, version: 1, onCreate: _onCreate);
  }

  Future<void> checkDatabase() async {
    Database db = await instance.database;
    List<Map<String, dynamic>> result = await db.query('characters');

    if (result.isEmpty) {
      print('Database is empty.');
    } else {
      for (var row in result) {
        print(row);
      }
    }
  }

  Future<void> _onCreate(Database db, int version) async {
    await db.execute('''
    CREATE TABLE characters (
      characterId TEXT PRIMARY KEY,
      name TEXT,
      story TEXT,
      description TEXT,
      age TEXT,
      background TEXT,
      skills TEXT,
      strengths TEXT,
      weaknesses TEXT,
      notableFeatures TEXT,
      isFavourite INTEGER
    )
    ''');
  }

  Future<int> insertCharacter(Character character) async {
    Database db = await instance.database;

    // character.characterId = nextCharacterId();
    return await db.insert('characters', character.toMapWithID(),
        conflictAlgorithm: ConflictAlgorithm.replace);
  }

  Future<List<Character>> getAllCharacters() async {
    Database db = await instance.database;
    var result = await db.query('characters');

    if (result.isNotEmpty) {
      return result.map((c) => Character.fromMap(c)).toList();
    }
    return [];
  }

  Future<Character?> getCharacterById(String characterId) async {
    Database db = await instance.database;
    var result = await db.query('characters',
        where: 'characterId = ?', whereArgs: [characterId]);
    return result.isNotEmpty ? Character.fromMap(result.first) : null;
  }

  Future<int> updateCharacter(Character character) async {
    Database db = await instance.database;
    return await db.update('characters', character.toMapWithID(),
        where: 'characterId = ?', whereArgs: [character.characterId]);
  }

  Future<int> deleteCharacter(String characterId) async {
    Database db = await instance.database;
    return await db.delete('characters',
        where: 'characterId = ?', whereArgs: [characterId]);
  }

  Future<int> deleteAllCharacters() async {
    Database db = await instance.database;
    return await db.delete('characters');
  }

  Future close() async {
    var dbClient = await database;
    dbClient.close();
  }

  String nextCharacterId() {
    var uuid = Uuid();
    return uuid.v4();
  }
}
