import 'dart:collection';

import '../../Model/Character.dart';

class CharacterService {
  final List<Character> _characters = [
    Character(
      name: "John Doe",
      story: "A mysterious traveler.",
      description: "A man with a complex past, always on the move.",
      age: "35",
      background:
          "Was raised in an orphanage and developed a knack for survival.",
      skills: "Fighting, negotiating, survival skills",
      strengths: "Strong, resilient, good strategist",
      weaknesses: "Tends to trust no one, haunted by past mistakes.",
      notableFeatures: "Has a scar on his left cheek from an old fight.",
      isFavourite: false,
      characterId: "1",
    ),
    Character(
      name: "Jane Smith",
      story: "A curious scientist.",
      description: "Highly intelligent and driven by the need for knowledge.",
      age: "29",
      background:
          "Grew up in a family of doctors, has always been interested in biology.",
      skills: "Scientific research, analysis, critical thinking",
      strengths: "Inventive, empathetic, logical",
      weaknesses:
          "Struggles with emotional connections due to her work obsession.",
      notableFeatures: "Wears glasses and often has her hair in a bun.",
      isFavourite: true,
      characterId: "2",
    ),
    Character(
      name: "Alice Johnson",
      story: "A skilled archer.",
      description:
          "A quiet and deadly archer, prefers solitude but fights for justice.",
      age: "27",
      background: "Spent her youth in the woods, learning from nature.",
      skills: "Archery, tracking, stealth",
      strengths: "Patient, perceptive, determined",
      weaknesses: "Can be overly cautious, often overanalyzing situations.",
      notableFeatures: "Her longbow is her prized possession.",
      isFavourite: false,
      characterId: "3",
    ),
  ];

  void addCharacter(Character character) {
    _characters.add(character);
  }

  void removeCharacter(String characterId) {
    _characters
        .removeWhere((character) => character.characterId == characterId);
  }

  Character? getCharacterById(String characterId) {
    return _characters.firstWhere(
      (character) => character.characterId == characterId,
      orElse: () => Character(),
    );
  }

  void updateCharacter(Character updatedCharacter) {
    final index = _characters.indexWhere(
        (character) => character.characterId == updatedCharacter.characterId);
    if (index != -1) {
      _characters[index] = updatedCharacter;
    }
  }

  List<Character> getAllCharacters() {
    return UnmodifiableListView(_characters);
  }
}
