import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:uuid/uuid.dart';
import '../Model/Character.dart';
import '../Service/CharacterService.dart';

class AddCharacterPage extends StatefulWidget {
  const AddCharacterPage({super.key});

  @override
  _AddCharacterPageState createState() => _AddCharacterPageState();
}

class _AddCharacterPageState extends State<AddCharacterPage> {
  late final TextEditingController nameController;
  late final TextEditingController storyController;
  late final TextEditingController descriptionController;
  late final TextEditingController ageController;
  late final TextEditingController backgroundController;
  late final TextEditingController skillsController;
  late final TextEditingController strengthsController;
  late final TextEditingController weaknessesController;
  late final TextEditingController notableFeaturesController;
  bool isFavourite = false;

  @override
  void initState() {
    super.initState();
    nameController = TextEditingController();
    storyController = TextEditingController();
    descriptionController = TextEditingController();
    ageController = TextEditingController();
    backgroundController = TextEditingController();
    skillsController = TextEditingController();
    strengthsController = TextEditingController();
    weaknessesController = TextEditingController();
    notableFeaturesController = TextEditingController();
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

  void showAlertDialog(BuildContext context, String message) {
    Widget okButton = TextButton(
      child: const Text("OK"),
      onPressed: () {
        Navigator.pop(context);
      },
    );

    AlertDialog alert = AlertDialog(
      title: const Text("Error"),
      content: Text(message),
      actions: [okButton],
    );

    showDialog(
      context: context,
      builder: (BuildContext context) {
        return alert;
      },
    );
  }

  bool _validateInputs() {
    if (nameController.text.isEmpty) {
      showAlertDialog(context, "Name is required.");
      return false;
    }
    if (storyController.text.isEmpty) {
      showAlertDialog(context, "Story is required.");
      return false;
    }
    if (descriptionController.text.isEmpty) {
      showAlertDialog(context, "Description is required.");
      return false;
    }
    return true;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        centerTitle: true,
        title: const Text('Add New Character'),
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            ListTile(
              title: TextField(
                controller: nameController,
                decoration: const InputDecoration(labelText: "Name"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: storyController,
                decoration: const InputDecoration(labelText: "Story"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: descriptionController,
                decoration: const InputDecoration(labelText: "Description"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: ageController,
                decoration: const InputDecoration(labelText: "Age"),
                keyboardType: TextInputType.number,
              ),
            ),
            ListTile(
              title: TextField(
                controller: backgroundController,
                decoration: const InputDecoration(labelText: "Background"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: skillsController,
                decoration: const InputDecoration(labelText: "Skills"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: strengthsController,
                decoration: const InputDecoration(labelText: "Strengths"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: weaknessesController,
                decoration: const InputDecoration(labelText: "Weaknesses"),
              ),
            ),
            ListTile(
              title: TextField(
                controller: notableFeaturesController,
                decoration: const InputDecoration(labelText: "Notable Features"),
              ),
            ),
            Row(
              children: [
                const Text("Mark as Favourite"),
                Switch(
                  value: isFavourite,
                  onChanged: (value) {
                    setState(() {
                      isFavourite = value;
                    });
                  },
                ),
              ],
            ),
            Center(
              child: ElevatedButton(
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.lightBlue,
                ),
                onPressed: () async {
                  if (_validateInputs()) {
                    String characterId = Uuid().v4();
                    final newName = nameController.text;
                    final newStory = storyController.text;
                    final newDescription = descriptionController.text;
                    final newAge = ageController.text;
                    final newBackground = backgroundController.text;
                    final newSkills = skillsController.text;
                    final newStrengths = strengthsController.text;
                    final newWeaknesses = weaknessesController.text;
                    final newNotableFeatures = notableFeaturesController.text;

                    await Provider.of<CharactersService>(context, listen: false).addCharacter(
                      characterId,
                      newName,
                      newStory,
                      newDescription,
                      newAge,
                      newBackground,
                      newSkills,
                      newStrengths,
                      newWeaknesses,
                      newNotableFeatures,
                      isFavourite,
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
                      isFavourite: isFavourite,
                      characterId: characterId,
                    );

                    Navigator.pop(context,character);
                  }
                },
                child: const Text(
                  "Add Character",
                  style: TextStyle(color: Colors.white),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
