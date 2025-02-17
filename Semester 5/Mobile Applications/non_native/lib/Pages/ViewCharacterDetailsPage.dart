import 'package:flutter/material.dart';

import '../Model/Character.dart';
import '../Services/CharacterRepository.dart';

class ViewCharacterDetailsPage extends StatefulWidget {
  final Character character;

  const ViewCharacterDetailsPage({super.key, required this.character});

  @override
  _ViewCharacterDetailsPageState createState() =>
      _ViewCharacterDetailsPageState();
}

class _ViewCharacterDetailsPageState extends State<ViewCharacterDetailsPage> {
  late TextEditingController _nameController;
  late TextEditingController _storyController;
  late TextEditingController _descriptionController;
  late TextEditingController _ageController;
  late TextEditingController _backgroundController;
  late TextEditingController _skillsController;
  late TextEditingController _strengthsController;
  late TextEditingController _weaknessesController;
  late TextEditingController _notableFeaturesController;

  final CharacterRepository _characterRepository = CharacterRepository();

  @override
  void initState() {
    super.initState();
    _nameController = TextEditingController(text: widget.character.name);
    _storyController = TextEditingController(text: widget.character.story);
    _descriptionController =
        TextEditingController(text: widget.character.description);
    _ageController = TextEditingController(text: widget.character.age);
    _backgroundController =
        TextEditingController(text: widget.character.background);
    _skillsController = TextEditingController(text: widget.character.skills);
    _strengthsController =
        TextEditingController(text: widget.character.strengths);
    _weaknessesController =
        TextEditingController(text: widget.character.weaknesses);
    _notableFeaturesController =
        TextEditingController(text: widget.character.notableFeatures);
  }

  @override
  void dispose() {
    _nameController.dispose();
    _storyController.dispose();
    _descriptionController.dispose();
    _ageController.dispose();
    _backgroundController.dispose();
    _skillsController.dispose();
    _strengthsController.dispose();
    _weaknessesController.dispose();
    _notableFeaturesController.dispose();
    super.dispose();
  }

  void _updateCharacter() async {
    final updatedCharacter = Character(
      characterId: widget.character.characterId,
      name: _nameController.text,
      story: _storyController.text,
      description: _descriptionController.text,
      age: _ageController.text,
      background: _backgroundController.text,
      skills: _skillsController.text,
      strengths: _strengthsController.text,
      weaknesses: _weaknessesController.text,
      notableFeatures: _notableFeaturesController.text,
      isFavourite: widget.character.isFavourite,
    );

    final success =
        await _characterRepository.updateCharacter(updatedCharacter);
    if (success) {
      Navigator.pop(context, updatedCharacter);
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Failed to update character.')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'View Character',
          style: TextStyle(color: Colors.white),
        ),
        backgroundColor: const Color(0xFF433259),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: SingleChildScrollView(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              TextField(
                controller: _nameController,
                decoration: const InputDecoration(labelText: 'Name'),
                maxLines: null,
              ),
              TextField(
                controller: _storyController,
                decoration: const InputDecoration(labelText: 'Story'),
                maxLines: null,
              ),
              TextField(
                controller: _descriptionController,
                decoration: const InputDecoration(labelText: 'Description'),
                maxLines: null,
              ),
              TextField(
                controller: _ageController,
                decoration: const InputDecoration(labelText: 'Age'),
                maxLines: null,
              ),
              TextField(
                controller: _backgroundController,
                decoration: const InputDecoration(labelText: 'Background'),
                maxLines: null,
              ),
              TextField(
                controller: _skillsController,
                decoration: const InputDecoration(labelText: 'Skills'),
                maxLines: null,
              ),
              TextField(
                controller: _strengthsController,
                decoration: const InputDecoration(labelText: 'Strengths'),
                maxLines: null,
              ),
              TextField(
                controller: _weaknessesController,
                decoration: const InputDecoration(labelText: 'Weaknesses'),
                maxLines: null,
              ),
              TextField(
                controller: _notableFeaturesController,
                decoration:
                    const InputDecoration(labelText: 'Notable Features'),
                maxLines: null,
              ),
              const SizedBox(height: 20),
            ],
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _updateCharacter,
        backgroundColor: const Color(0xFF433259),
        child: const Icon(
          Icons.save,
          color: Colors.white,
        ),
      ),
    );
  }
}
