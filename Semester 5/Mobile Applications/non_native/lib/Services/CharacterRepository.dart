import 'package:non_native/Services/DatabaseContext.dart';

import '../Model/Character.dart';

class CharacterRepository {
  final DatabaseContext _databaseHelper = DatabaseContext.instance;

  Future<bool> addCharacter(Character character) async {
    return await _databaseHelper.insertCharacter(character) > 0;
  }
  
  Future<Character?> getCharacterById(String characterId) async {
    return await _databaseHelper.getCharacterById(characterId);
  }

  Future<bool> updateCharacter(Character character) async {
    return await _databaseHelper.updateCharacter(character) > 0;
  }

  Future<bool> removeCharacter(String characterId) async {
    return await _databaseHelper.deleteCharacter(characterId) > 0;
  }

  Future<List<Character>> getAllCharacters() async {
    return await _databaseHelper.getAllCharacters();
  }

  Future<bool> deleteAllCharacters() async {
    return await _databaseHelper.deleteAllCharacters() > 0;
  }
}