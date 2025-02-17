package com.example.nativekotlin.service

import android.content.Intent
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import android.view.MenuItem
import android.view.View
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import com.example.nativekotlin.model.Character
import com.example.nativekotlin.model.CharactersHelper
import com.example.nativekotlin.R
import com.example.nativekotlin.databinding.ActivityCharacterDetailBinding

class CharacterDetailActivity : AppCompatActivity(), TextWatcher {
    lateinit var binding: ActivityCharacterDetailBinding
    private var character: Character = Character()
    private var characterId: Int? = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        binding = ActivityCharacterDetailBinding.inflate(layoutInflater);
        setContentView(binding.root)

        setSupportActionBar(binding.detailToolbar)

        binding.saveButton.setOnClickListener(onClickListener)
        supportActionBar?.setDisplayHomeAsUpEnabled(true)

        if (savedInstanceState == null) {
            characterId = intent.getStringExtra(CharacterDetailFragment.CURRENT_ITEM_ID)?.toInt()
            val fragment = CharacterDetailFragment().apply {
                arguments = Bundle().apply {
                    putString(
                        CharacterDetailFragment.CURRENT_ITEM_ID,
                        intent.getStringExtra(CharacterDetailFragment.CURRENT_ITEM_ID)
                    )
                }
            }

            supportFragmentManager.beginTransaction()
                .add(R.id.linear_layout, fragment)
                .commit()
        }
    }

    private val onClickListener: View.OnClickListener = View.OnClickListener { view ->
        if(isValid()){
            character.name = binding.nameInputCreate.text.toString()
            character.story = binding.storyInputCreate.text.toString()
            character.age = binding.ageInputCreate.text.toString()
            character.description = binding.descriptionInputCreate.text.toString()
            character.background = binding.backgroundInputCreate.text.toString()
            character.skills = binding.skillsInputCreate.text.toString()
            character.strengths = binding.strengthsInputCreate.text.toString()
            character.weaknesses = binding.weaknessesInputCreate.text.toString()
            character.notableFeatures = binding.notableFeaturesInputCreate.text.toString()
            character.isFavourite = binding.favoriteCheckbox.isChecked

            if(characterId != -1) {
                CharactersHelper.characters.find() { it.characterId == characterId.toString() }?.apply {
                    name = character.name
                    story = character.story
                    age = character.age
                    description = character.description
                    background = character.background
                    skills = character.skills
                    strengths = character.strengths
                    weaknesses = character.weaknesses
                    notableFeatures = character.notableFeatures
                    isFavourite = character.isFavourite
                }
                CharactersHelper.charactersWithId[characterId.toString()] = character
                setResult(characterId!!)

                Log.d("TAG", "updated item no $characterId")
                finish()
            } else {
                character.characterId = (CharactersHelper.INDEX+1).toString()
                CharactersHelper.characters.add(character)
                CharactersHelper.charactersWithId[(CharactersHelper.INDEX+1).toString()] = character
                setResult(CharactersHelper.characters.size - 1, Intent())

                CharactersHelper.INDEX++
                Log.d("TAG", "added item no ${CharactersHelper.characters.size}")
                Log.i("Added character", character.toString())
                finish()
            }
        }
    }

    private fun isValid() : Boolean {
        if (binding.nameInputCreate.text.toString().isEmpty()) {
            binding.nameInputCreate.error = "Please enter a name"
            return false
        }

        if (binding.descriptionInputCreate.text.toString().isEmpty()) {
            binding.descriptionInputCreate.error = "Please write at least a small description > - <"
            return false
        }

        return true
    }

    override fun onOptionsItemSelected(item: MenuItem) =
        when (item.itemId) {
            android.R.id.home -> {
                setResult(0)
                finish()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }

    override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {
        TODO("Not necessary yet")
    }

    override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
        TODO("Not necessary yet")
    }

    override fun afterTextChanged(s: Editable?) {
        TODO("Not necessary yet")
    }
}