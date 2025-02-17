package com.example.nativekotlin

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.nativekotlin.databinding.ActivityMainBinding
import com.example.nativekotlin.service.ListViewActivity

class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater);
        setContentView(binding.root);

        binding.startButton.setOnClickListener {
            val intent = Intent(this, ListViewActivity::class.java);
            startActivity(intent);
        }
    }
}