package com.example.nativekotlin.model

object CharactersHelper {
    val characters: MutableList<Character> = ArrayList()
    val charactersWithId: MutableMap<String, Character> = HashMap()
    var INDEX = 5

    init {
        populateCharactersList().forEach { addCharacter(it) }
    }

    private fun addCharacter(character: Character) {
        characters.add(character)
        charactersWithId[character.characterId] = character
    }

    private fun populateCharactersList(): MutableList<Character> {
        return mutableListOf(
            Character(
                "John Doe",
                "A mysterious traveler.",
                "A man with a complex past, always on the move.",
                "35",
                "Was raised in an orphanage and developed a knack for survival.",
                "Fighting, negotiating, survival skills",
                "Strong, resilient, good strategist",
                "Tends to trust no one, haunted by past mistakes.",
                "Has a scar on his left cheek from an old fight.",
                false,
                "1"
            ),
            Character(
                "Jane Smith",
                "A curious scientist.",
                "Highly intelligent and driven by the need for knowledge.",
                "29",
                "Grew up in a family of doctors, has always been interested in biology.",
                "Scientific research, analysis, critical thinking",
                "Inventive, empathetic, logical",
                "Struggles with emotional connections due to her work obsession.",
                "Wears glasses and often has her hair in a bun.",
                true,
                "2"
            ),
            Character(
                "Alice Johnson",
                "A skilled archer.",
                "A quiet and deadly archer, prefers solitude but fights for justice.",
                "27",
                "Spent her youth in the woods, learning from nature.",
                "Archery, tracking, stealth",
                "Patient, perceptive, determined",
                "Can be overly cautious, often overanalyzing situations.",
                "Her longbow is her prized possession.",
                false, "3"

            ),
            Character(
                "Michael Knight",
                "A former soldier turned mercenary.",
                "Ex-soldier who now works as a mercenary, loyal to those who pay well.",
                "40",
                "Served in multiple military campaigns, now operates as a lone wolf.",
                "Combat, strategy, leadership",
                "Disciplined, brave, emotionally distant",
                "Has a short temper and struggles with authority.",
                "Has tattoos from his military service.",
                true,
                "4"
            ),
            Character(
                "Sophia Williams",
                "A quiet librarian with a secret.",
                "A seemingly ordinary librarian, but she hides a dark past.",
                "32",
                "Studied literature and history, but also dabbled in forbidden knowledge.",
                "Reading, research, puzzle-solving",
                "Wise, patient, secretive",
                "Afraid of her past catching up to her.",
                "Always carries a book with her.",
                false,
                "5"
            )
        )
    }

}