import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../Model/Character.dart';
import '../Service/CharacterService.dart';
import '../Widgets/CharacterWidget.dart';
import 'AddCharacterPage.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key, required this.title});

  final String title;

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  late CharactersService _charactersService;
  bool initLocally = false;
  List<Character> _characters = [];

  @override
  void initState() {
    super.initState();
    _charactersService = context.read<CharactersService>();
    _loadCharacters();
    _charactersService.addListener(_loadCharacters);
  }

  @override
  void dispose() {
    _charactersService.removeListener(_loadCharacters);
    super.dispose();
  }

    Future<void> _loadCharacters() async {
    try {
      final characters = await _charactersService.getAllCharacters(initLocally);
      setState(() {
        _characters.addAll(
            characters.left.where((newCharacter) => !_characters.any(
                    (existingCharacter) => existingCharacter == newCharacter)));
      });
      initLocally = false;
    } catch (error) {
      _showSnackBar('Error fetching characters: $error', Colors.red);
    }
  }

  Future<void> _navigateToAddCharacterPage() async {
    final newCharacter = await Navigator.push<Character>(
      context,
      MaterialPageRoute(builder: (context) => const AddCharacterPage()),
    );

    if (newCharacter != null) {
      setState(() => _characters.add(newCharacter));
    }
  }

  Future<void> _deleteCharacter(String characterId) async {
    final success = await _charactersService.removeCharacter(characterId);
    if (success) {
      setState(() => _characters.removeWhere((character) => character.characterId == characterId));
    } else {
      _showSnackBar('Failed to delete character. Please try again.', Colors.red);
    }
  }

  Future<void> _updateCharacter(Character updatedCharacter) async {
    final success = await _charactersService.updateCharacter(
      updatedCharacter.characterId,
      updatedCharacter.name,
      updatedCharacter.story,
      updatedCharacter.description,
      updatedCharacter.age,
      updatedCharacter.background,
      updatedCharacter.skills,
      updatedCharacter.strengths,
      updatedCharacter.weaknesses,
      updatedCharacter.notableFeatures,
    );

    if (success) {
      final index = _characters.indexWhere((character) =>
      character.characterId == updatedCharacter.characterId);
      if (index != -1) {
        setState(() => _characters[index] = updatedCharacter);
      }
    } else {
      _showSnackBar('Failed to update character. Please try again.', Colors.red);
    }
  }

  void _showSnackBar(String message, Color color) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text(message), backgroundColor: color),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF433259),
        title: Text(
          widget.title,
          style: const TextStyle(color: Colors.white, fontSize: 25),
        ),
        toolbarHeight: 200,
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _navigateToAddCharacterPage,
        backgroundColor: const Color(0xFF433259),
        child: const Icon(Icons.add, color: Colors.white),
      ),
      body: _buildBody(),
    );
  }

  Widget _buildBody() {
    if (_characters.isEmpty) {
      return const Center(child: CircularProgressIndicator());
    }

    return ListView.builder(
      itemCount: _characters.length,
      itemBuilder: (context, index) {
        final character = _characters[index];
        return CharacterWidget(
          character: character,
          onDelete: _deleteCharacter,
          onUpdate: _updateCharacter,
        );
      },
    );
  }
}
