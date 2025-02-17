import 'package:flutter/material.dart';

import '../Model/Character.dart';
import '../Services/CharacterRepository.dart';
import '../Widgets/CharacterWidget.dart';
import 'AddCharacterPage.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key, required this.title});

  final String title;

  @override
  State<Homepage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<Homepage> {
  final CharacterRepository _characterRepository = CharacterRepository();
  late List<Character> _characters = [];

  @override
  void initState() {
    super.initState();
    _loadCharacters();
  }

  Future<void> _loadCharacters() async {
    final characters = await _characterRepository.getAllCharacters();
    setState(() {
      _characters = characters;
    });
  }

  Future<void> _navigateToAddCharacterPage() async {
    final newCharacter = await Navigator.push<Character>(
      context,
      MaterialPageRoute(builder: (context) => const AddCharacterPage()),
    );

    if (newCharacter != null) {
      setState(() {
        _characters.add(newCharacter);
      });
    }
  }

  Future<void> _deleteCharacter(String characterId) async {
    final success = await _characterRepository.removeCharacter(characterId);
    if (success) {
      setState(() {
        _characters
            .removeWhere((character) => character.characterId == characterId);
      });
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Failed to delete character. Please try again.'),
          backgroundColor: Colors.red,
        ),
      );
    }
  }

  Future<void> _updateCharacter(Character updatedCharacter) async {
    final success =
        await _characterRepository.updateCharacter(updatedCharacter);
    if (success) {
      setState(() {
        final index = _characters.indexWhere((character) =>
            character.characterId == updatedCharacter.characterId);
        if (index != -1) {
          _characters[index] = updatedCharacter;
        }
      });
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Failed to update character. Please try again.'),
          backgroundColor: Colors.red,
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF433259),
        title: const Text(
          'Genesis',
          style: TextStyle(color: Colors.white, fontSize: 25),
        ),
        toolbarHeight: 200,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text(
              'Characters List',
              style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
                color: Color(0xFF433259),
              ),
            ),
            const SizedBox(height: 16),
            // The list of characters
            Expanded(
              child: _characters.isEmpty
                  ? const Center(
                      child: Text(
                        'No characters available.',
                        style: TextStyle(color: Colors.grey, fontSize: 16),
                      ),
                    )
                  : ListView.builder(
                      itemCount: _characters.length,
                      itemBuilder: (context, index) {
                        final character = _characters[index];
                        return CharacterWidget(
                          character: character,
                          onDelete: _deleteCharacter,
                          onUpdate: _updateCharacter,
                        );
                      },
                    ),
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _navigateToAddCharacterPage,
        backgroundColor: const Color(0xFF433259),
        child: const Icon(
          Icons.add, // Plus sign
          color: Colors.white,
        ),
      ),
    );
  }
}
