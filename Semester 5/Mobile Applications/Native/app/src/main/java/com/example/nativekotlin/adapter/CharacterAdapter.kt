package com.example.nativekotlin.adapter

import android.app.AlertDialog
import android.content.Intent
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.nativekotlin.model.Character
import com.example.nativekotlin.model.CharactersHelper
import com.example.nativekotlin.service.CharacterDetailFragment
import com.example.nativekotlin.R
import com.example.nativekotlin.service.CharacterDetailActivity
import com.google.android.material.snackbar.Snackbar

class CharacterAdapter(private val characters: MutableList<Character>):
    RecyclerView.Adapter<CharacterAdapter.CharacterViewHolder>() {

    class CharacterViewHolder(view: View): RecyclerView.ViewHolder(view) {
        val characterNameTextView: TextView = itemView.findViewById(R.id.character_name_id)
        val storyTextView: TextView = itemView.findViewById(R.id.story_id)
        val characterDescriptionTextView: TextView = itemView.findViewById(R.id.description_id)

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): CharacterViewHolder {
        val textView = LayoutInflater.from(parent.context)
            .inflate(R.layout.character_card_list_content, parent, false)
        return CharacterViewHolder(textView)
    }

    override fun onBindViewHolder(holder: CharacterViewHolder, position: Int) {
        val item = characters[position]

        holder.characterNameTextView.text = item.name
        holder.storyTextView.text = item.story
        holder.characterDescriptionTextView.text = item.description

        with(holder.itemView) {
            tag = item
            setOnClickListener(onClickListener)
            setOnLongClickListener(onLongClickListener)
        }
        with(holder.itemView) {
            tag = item
            setOnLongClickListener(onLongClickListener)
        }
    }

    override fun getItemCount(): Int {
        return CharactersHelper.characters.size
    }

    private val onClickListener: View.OnClickListener = View.OnClickListener { view ->
        val item = view.tag as Character
        val intent = Intent(view.context, CharacterDetailActivity::class.java).apply {
            putExtra(CharacterDetailFragment.CURRENT_ITEM_ID, item.characterId)
        }
        view.context.startActivity(intent)
    }

    private val onLongClickListener: View.OnLongClickListener =  View.OnLongClickListener{ view ->
        val item = view.tag as Character
        val builder = AlertDialog.Builder(view.context)
        builder.setMessage("Are you sure you want to delete this blorbo?")
            .setCancelable(false)
            .setPositiveButton("Yes, to creative Hell with it!") { _, _ ->
                this.notifyItemRemoved(CharactersHelper.characters.indexOf(item))
                characters.remove(item)
                CharactersHelper.charactersWithId.remove(item.characterId)
                CharactersHelper.characters.remove(item)
                Snackbar.make(view, "Back to the ether it goes", Snackbar.LENGTH_LONG)
                    .setAction("Action: deletion", null).show()
            }
            .setNegativeButton("Never mind, put it back") { dialog, _ ->
                dialog.dismiss()
            }
        Log.i("Current list of characters", CharactersHelper.charactersWithId.keys.toString())
        val alert = builder.create()
        alert.show()
        true
    }
}