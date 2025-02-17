class Character {
  String characterId;
  String name;
  String story;
  String description;
  String age;
  String background;
  String skills;
  String strengths;
  String weaknesses;
  String notableFeatures;
  bool isFavourite;

  Character({
    this.name = "",
    this.story = "",
    this.description = "",
    this.age = "",
    this.background = "",
    this.skills = "",
    this.strengths = "",
    this.weaknesses = "",
    this.notableFeatures = "",
    this.isFavourite = false,
    this.characterId = "-1",
  });

  Map<String, dynamic> toMap() {
    return {
      'characterId': characterId,
      'name': name,
      'story': story,
      'description': description,
      'age': age,
      'background': background,
      'skills': skills,
      'strengths': strengths,
      'weaknesses': weaknesses,
      'notableFeatures': notableFeatures,
      'isFavourite': isFavourite ? 1 : 0
    };
  }

  factory Character.fromMap(Map<String, dynamic> map) {
    return Character(
      characterId: map['characterId'] ?? '-1',
      name: map['name'] ?? '',
      story: map['story'] ?? '',
      description: map['description'] ?? '',
      age: map['age'] ?? '',
      background: map['background'] ?? '',
      skills: map['skills'] ?? '',
      strengths: map['strengths'] ?? '',
      weaknesses: map['weaknesses'] ?? '',
      notableFeatures: map['notableFeatures'] ?? '',
      isFavourite: map['isFavourite'] == 1, // Convert INTEGER to bool
    );
  }

  @override
  String toString() {
    return 'Character(name: $name, story: $story, description: $description, age: $age, characterId: $characterId)';
  }
}