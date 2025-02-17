import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../Model/Character.dart';
import '../Service/CharacterService.dart';

class ViewCharacterDetailsPage extends StatefulWidget {
  final Character character;

  const ViewCharacterDetailsPage({super.key, required this.character});

  @override
  _ViewCharacterDetailsPageState createState() =>
      _ViewCharacterDetailsPageState();
}

class _ViewCharacterDetailsPageState extends State<ViewCharacterDetailsPage> {
  late TextEditingController nameController;
  late TextEditingController storyController;
  late TextEditingController descriptionController;
  late TextEditingController ageController;
  late TextEditingController backgroundController;
  late TextEditingController skillsController;
  late TextEditingController strengthsController;
  late TextEditingController weaknessesController;
  late TextEditingController notableFeaturesController;
  late final

  String _errorMessage = '';

  @override
  void initState() {
    super.initState();
    nameController = TextEditingController(text: widget.character.name);
    storyController = TextEditingController(text: widget.character.story);
    descriptionController =
        TextEditingController(text: widget.character.description);
    ageController = TextEditingController(text: widget.character.age);
    backgroundController =
        TextEditingController(text: widget.character.background);
    skillsController = TextEditingController(text: widget.character.skills);
    strengthsController =
        TextEditingController(text: widget.character.strengths);
    weaknessesController =
        TextEditingController(text: widget.character.weaknesses);
    notableFeaturesController =
        TextEditingController(text: widget.character.notableFeatures);

  }

  @override
  void dispose() {
    nameController.dispose();
    storyController.dispose();
    descriptionController.dispose();
    ageController.dispose();
    backgroundController.dispose();
    skillsController.dispose();
    strengthsController.dispose();
    weaknessesController.dispose();
    notableFeaturesController.dispose();
    super.dispose();
  }

  void showAlertDialog(String message) {
    Widget okButton = TextButton(
      child: const Text("OK"),
      onPressed: () {
        Navigator.pop(context);
      },
    );

    AlertDialog alert = AlertDialog(
      title: const Text("Error"),
      content: Text(message),
      actions: [
        okButton,
      ],
    );

    showDialog(
      context: context,
      builder: (BuildContext context) {
        return alert;
      },
    );
  }

  bool _validateInputs() {
    if (nameController.text.isEmpty ||
        storyController.text.isEmpty ||
        descriptionController.text.isEmpty) {
      showAlertDialog("These fields are required.");
      return false;
    }
    return true;
  }

  Future<void> _updateCharacter() async {
    if (_validateInputs()) {
      final newName = nameController.text;
      final newStory = storyController.text;
      final newDescription = descriptionController.text;
      final newAge = ageController.text;
      final newBackground = backgroundController.text;
      final newSkills = skillsController.text;
      final newStrengths = strengthsController.text;
      final newWeaknesses = weaknessesController.text;
      final newNotableFeatures = notableFeaturesController.text;

      await Provider.of<CharactersService>(context, listen: false).updateCharacter(
        widget.character.characterId,
        newName,
        newStory,
        newDescription,
        newAge,
        newBackground,
        newSkills,
        newStrengths,
        newWeaknesses,
        newNotableFeatures,
      );

      var character = Character(
        name : newName,
        story: newStory,
        description: newDescription,
        age: newAge,
        background: newBackground,
        skills: newSkills,
        strengths: newStrengths,
        weaknesses: newWeaknesses,
        notableFeatures: newNotableFeatures,
        isFavourite: widget.character.isFavourite,
        characterId: widget.character.characterId,
      );

      Navigator.pop(context,character);
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
                controller: nameController,
                decoration: const InputDecoration(labelText: 'Name'),
                maxLines: null,
              ),
              TextField(
                controller: storyController,
                decoration: const InputDecoration(labelText: 'Story'),
                maxLines: null,
              ),
              TextField(
                controller: descriptionController,
                decoration: const InputDecoration(labelText: 'Description'),
                maxLines: null,
              ),
              TextField(
                controller: ageController,
                decoration: const InputDecoration(labelText: 'Age'),
                maxLines: null,
              ),

              TextField(
                controller: backgroundController,
                decoration: const InputDecoration(labelText: 'Background'),
                maxLines: null,
              ),
              TextField(
                controller: skillsController,
                decoration: const InputDecoration(labelText: 'Skills'),
                maxLines: null,
              ),
              TextField(
                controller: strengthsController,
                decoration: const InputDecoration(labelText: 'Strengths'),
                maxLines: null,
              ),
              TextField(
                controller: weaknessesController,
                decoration: const InputDecoration(labelText: 'Weaknesses'),
                maxLines: null,
              ),
              TextField(
                controller: notableFeaturesController,
                decoration:
                const InputDecoration(labelText: 'Notable Features'),
                maxLines: null,
              ),
              const SizedBox(height: 20),
              _errorMessage.isNotEmpty
                  ? Text(
                _errorMessage,
                style: const TextStyle(color: Colors.red),
              )
                  : const SizedBox.shrink(),
            ],
          ),
        ),
      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          FloatingActionButton(
            onPressed: _updateCharacter,
            backgroundColor: const Color(0xFF433259),
            child: const Icon(
              Icons.save,
              color: Colors.white,
            ),
          ),
          const SizedBox(height: 16)
        ],
      ),
    );
  }
}
