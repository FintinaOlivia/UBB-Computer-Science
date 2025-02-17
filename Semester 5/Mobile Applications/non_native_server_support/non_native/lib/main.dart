import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../Pages/Homepage.dart';
import 'Service/CharacterService.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  var service = await CharactersService.init();

  runApp(
    ChangeNotifierProvider(
      create: (_) => service,
      child: const MyApp(),
    ),
  );
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
      home: Homepage(title: 'Genesis: Character Builder'),
    );
  }
}

class MainPage extends StatelessWidget {
  const MainPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF433259),
        title: const Text(
          'Genesis: Character Builder',
          style: TextStyle(color: Colors.white, fontSize: 18),
        ),
      ),
      body: Column(
        children: [
          const ConnectionStatusWidget(),
          Expanded(
            child: const Homepage(title: 'Genesis: Character Builder'),
          ),
        ],
      ),
    );
  }
}

class ConnectionStatusWidget extends StatelessWidget {
  const ConnectionStatusWidget({super.key});

  @override
  Widget build(BuildContext context) {
    return Consumer<CharactersService>(
      builder: (context, service, child) {
        return Container(
          color: service.is_online ? Colors.lightGreen : Colors.red,
          width: double.infinity,
          padding: const EdgeInsets.all(8),
          child: Text(
            service.is_online ? 'Online' : 'Offline',
            style: const TextStyle(color: Colors.white),
            textAlign: TextAlign.center,
          ),
        );
      },
    );
  }
}
