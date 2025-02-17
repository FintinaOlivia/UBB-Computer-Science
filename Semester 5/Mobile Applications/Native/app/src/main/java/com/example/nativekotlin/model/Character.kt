package com.example.nativekotlin.model

import android.os.Parcelable
import android.util.Log
import kotlinx.parcelize.Parcelize

@Parcelize
data class Character(
    var name: String = "",
    var story: String = "",
    var description: String = "",
    var age: String = "",
    var background: String = "",
    var skills: String = "",
    var strengths: String = "",
    var weaknesses: String = "",
    var notableFeatures: String = "",
    var isFavourite: Boolean = false,
    var characterId: String = "0"
) : Parcelable {
    init {
        Log.i("Model Character Class: ", "CurrentId is $characterId")
    }
}
