import 'package:flutter/material.dart';

import '../Model/Character.dart';
import '../Services/CharacterRepository.dart';

class AddCharacterPage extends StatefulWidget {
  const AddCharacterPage({super.key});

  @override
  _AddCharacterPageState createState() => _AddCharacterPageState();
}

class _AddCharacterPageState extends State<AddCharacterPage> {
  final _formKey = GlobalKey<FormState>();
  final _nameController = TextEditingController();
  final _storyController = TextEditingController();
  final _descriptionController = TextEditingController();
  final _ageController = TextEditingController();
  final _backgroundController = TextEditingController();
  final _skillsController = TextEditingController();
  final _strengthsController = TextEditingController();
  final _weaknessesController = TextEditingController();
  final _notableFeaturesController = TextEditingController();
  bool _isFavourite = false;

  final CharacterRepository _characterRepository = CharacterRepository();

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

  Future<void> _submitForm() async {
    if (_formKey.currentState!.validate()) {
      final newCharacter = Character(
        characterId: DateTime.now().millisecondsSinceEpoch.toString(),
        name: _nameController.text,
        story: _storyController.text,
        description: _descriptionController.text,
        age: _ageController.text,
        background: _backgroundController.text,
        skills: _skillsController.text,
        strengths: _strengthsController.text,
        weaknesses: _weaknessesController.text,
        notableFeatures: _notableFeaturesController.text,
        isFavourite: _isFavourite,
      );

      final success = await _characterRepository.addCharacter(newCharacter);
      if (success) {
        Navigator.pop(context, newCharacter);
      } else {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text('Failed to add character.')),
        );
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Add Character")),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: SingleChildScrollView(
            child: Column(
              children: [
                TextFormField(
                  controller: _nameController,
                  decoration: const InputDecoration(labelText: "Name"),
                  validator: (value) => value!.isEmpty ? "Enter a name" : null,
                  maxLines: null,
                ),
                TextFormField(
                  controller: _storyController,
                  decoration: const InputDecoration(labelText: "Story"),
                  validator: (value) => value!.isEmpty ? "Enter a story" : null,
                  maxLines: null,
                ),
                TextFormField(
                  controller: _descriptionController,
                  decoration: const InputDecoration(labelText: "Description"),
                  validator: (value) =>
                      value!.isEmpty ? "Enter a description" : null,
                  maxLines: null,
                ),
                TextFormField(
                  controller: _ageController,
                  decoration: const InputDecoration(labelText: "Age"),
                  keyboardType: TextInputType.number,
                  maxLines: null,
                ),
                TextFormField(
                  controller: _backgroundController,
                  decoration: const InputDecoration(labelText: "Background"),
                  maxLines: null,
                ),
                TextFormField(
                  controller: _skillsController,
                  decoration: const InputDecoration(labelText: "Skills"),
                  maxLines: null,
                ),
                TextFormField(
                  controller: _strengthsController,
                  decoration: const InputDecoration(labelText: "Strengths"),
                  maxLines: null,
                ),
                TextFormField(
                  controller: _weaknessesController,
                  decoration: const InputDecoration(labelText: "Weaknesses"),
                  maxLines: null,
                ),
                TextFormField(
                  controller: _notableFeaturesController,
                  decoration:
                      const InputDecoration(labelText: "Notable Features"),
                ),
                const SizedBox(height: 10),
                Row(
                  children: [
                    const Text("Mark as Favourite"),
                    Switch(
                      value: _isFavourite,
                      onChanged: (value) {
                        setState(() {
                          _isFavourite = value;
                        });
                      },
                    ),
                  ],
                ),
                const SizedBox(height: 20),
              ],
            ),
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _submitForm,
        backgroundColor: const Color(0xFF433259),
        child: const Icon(
          Icons.save,
          color: Colors.white,
        ),
      ),
    );
  }
}
