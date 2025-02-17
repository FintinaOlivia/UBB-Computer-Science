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

  Map<String, dynamic> toMapWithID() {
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

  Map<String, dynamic> toMap() {
    return {
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
    var character = Character(
      name: map['name'] ?? '',
      story: map['story'] ?? '',
      description: map['description'] ?? '',
      age: map['age'] ?? '',
      background: map['background'] ?? '',
      skills: map['skills'] ?? '',
      strengths: map['strengths'] ?? '',
      weaknesses: map['weaknesses'] ?? '',
      notableFeatures: map['notableFeatures'] ?? '',
      isFavourite: map['isFavourite'] == 1,
    );
    character.characterId = map['characterId'];
    return character;
  }

  Map<String, dynamic> toJson() {
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
      'isFavourite': isFavourite,
    };
  }

  factory Character.fromJson(Map<String, dynamic> map) {
    return Character(
      characterId:  map['characterId'] is String
          ? map['characterId']
          : map['characterId'].toString(),
      name: map['name'],
      story: map['story'],
      description: map['description'],
      age: map['age'],
      background: map['background'],
      skills: map['skills'],
      strengths: map['strengths'],
      weaknesses: map['weaknesses'],
      notableFeatures: map['notableFeatures'],
      isFavourite: false,
    );
  }

  @override
  String toString() {
    return 'Character(name: $name, story: $story, description: $description, age: $age, characterId: $characterId)';
  }

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;
    if (other is! Character) return false;
    return characterId == other.characterId &&
        name == other.name &&
        story == other.story &&
        description == other.description &&
        age == other.age &&
        background == other.background &&
        skills == other.skills &&
        strengths == other.strengths &&
        weaknesses == other.weaknesses &&
        notableFeatures == other.notableFeatures &&
        isFavourite == other.isFavourite;
  }
}