package com.example.nativekotlin.service

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import com.example.nativekotlin.model.Character
import com.example.nativekotlin.model.CharactersHelper
import com.example.nativekotlin.databinding.CharacterDetailBinding

class CharacterDetailFragment: Fragment() {
    private lateinit var character: Character
    private var binding: CharacterDetailBinding? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        arguments?.let {
            if (it.containsKey(CURRENT_ITEM_ID)) {
                if (it.getString(CURRENT_ITEM_ID) == "-1") {
                    populateCharacterWithNewData()
                } else {
                    populateCharacterWithExistingData(it)
                }
            }
        }
    }

    private fun populateCharacterWithExistingData(bundle: Bundle) {
        character = CharactersHelper.charactersWithId[bundle.getString(CURRENT_ITEM_ID)]!!
        Log.i("Populate character with data","Character: $character")

        (activity as? CharacterDetailActivity)?.binding?.detailToolbar?.title = character.name
        (activity as? CharacterDetailActivity)?.binding?.nameInputCreate?.setText(character.name)
        (activity as? CharacterDetailActivity)?.binding?.storyInputCreate?.setText(character.story)
        (activity as? CharacterDetailActivity)?.binding?.ageInputCreate?.setText(character.age)
        (activity as? CharacterDetailActivity)?.binding?.descriptionInputCreate?.setText(character.description)
        (activity as? CharacterDetailActivity)?.binding?.backgroundInputCreate?.setText(character.background)
        (activity as? CharacterDetailActivity)?.binding?.skillsInputCreate?.setText(character.skills)
        (activity as? CharacterDetailActivity)?.binding?.strengthsInputCreate?.setText(character.strengths)
        (activity as? CharacterDetailActivity)?.binding?.weaknessesInputCreate?.setText(character.weaknesses)
        (activity as? CharacterDetailActivity)?.binding?.notableFeaturesInputCreate?.setText(character.notableFeatures)
        (activity as? CharacterDetailActivity)?.binding?.favoriteCheckbox?.isChecked = character.isFavourite

    }

    private fun populateCharacterWithNewData() {
        (activity as? CharacterDetailActivity)?.binding?.detailToolbar?.title = "New Character"
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        binding = CharacterDetailBinding.inflate(inflater, container, false)
        return binding!!.root
    }

    override fun onDestroyView() {
        super.onDestroyView()
        binding = null
    }

    companion object {
        const val CURRENT_ITEM_ID = "item_id"
    }
}