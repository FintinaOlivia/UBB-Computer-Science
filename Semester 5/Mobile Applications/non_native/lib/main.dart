import 'package:flutter/material.dart';
import 'package:non_native/Pages/Homepage.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Genesis',
      theme: ThemeData(
        primaryColor: const Color(0xFF433259),
        useMaterial3: true,
      ),
      home: const Homepage(title: 'Genesis: Character Builder'),
    );
  }
}