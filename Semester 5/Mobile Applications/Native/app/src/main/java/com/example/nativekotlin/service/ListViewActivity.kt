package com.example.nativekotlin.service

import android.annotation.SuppressLint
import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.RecyclerView
import com.example.nativekotlin.adapter.CharacterAdapter
import com.example.nativekotlin.model.CharactersHelper
import com.example.nativekotlin.databinding.ActivityCharacterListViewBinding
import com.example.nativekotlin.databinding.CharacterListBinding

class ListViewActivity : AppCompatActivity() {
    private var binding: ActivityCharacterListViewBinding? = null
    private var characterListBinding: CharacterListBinding? = null

    private val characterDetailLauncher = registerForActivityResult(
        ActivityResultContracts.StartActivityForResult()
    ) { result ->
        if (result.resultCode == Activity.RESULT_OK) {
            characterListBinding?.characterList?.adapter?.notifyItemInserted(
                CharactersHelper.characters.size - 1
            )
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityCharacterListViewBinding.inflate(layoutInflater)
        characterListBinding = binding!!.characterListId
        setContentView(binding!!.root)

        setupRecyclerView(characterListBinding!!.characterList)
        setSupportActionBar(binding!!.toolbar)

        binding!!.addButton.setOnClickListener(onClickListener)
    }


    @SuppressLint("NotifyDataSetChanged")
    override fun onResume() {
        super.onResume()
        characterListBinding!!.characterList.adapter?.notifyDataSetChanged()
    }

    private fun setupRecyclerView(recyclerView: RecyclerView) {
        recyclerView.adapter = CharacterAdapter(CharactersHelper.characters)  // populate item list
    }

    private val onClickListener: View.OnClickListener = View.OnClickListener { v ->
        val intent = Intent(v.context, CharacterDetailActivity::class.java).apply {
            putExtra(CharacterDetailFragment.CURRENT_ITEM_ID, "-1")
        }
        characterDetailLauncher.launch(intent)
    }
}