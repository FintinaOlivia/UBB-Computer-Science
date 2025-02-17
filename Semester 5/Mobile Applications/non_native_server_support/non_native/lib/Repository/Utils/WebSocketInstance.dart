import 'dart:developer';

import 'package:web_socket_channel/web_socket_channel.dart';

class WebSocketInstance {
  static final WebSocketInstance _instance = WebSocketInstance._internal();
  late WebSocketChannel _channel;
  bool _isConnected = false;

  WebSocketInstance._internal();

  factory WebSocketInstance() {
    return _instance;
  }

  bool get isConnected => _isConnected;
  Stream<String> get stream => _channel.stream.map((data) => data.toString());

  Future<void> connect(String ipAddress) async {
    if (_isConnected) return;

    try {
      _channel = WebSocketChannel.connect(Uri.parse("ws://$ipAddress:8080/ws"));
      _channel.stream.listen(
            (data) => _handleServerMessage(data),
        onDone: _reconnect,
        onError: (error) => log('WebSocket error: $error'),
      );
      _isConnected = true;
    } catch (e) {
      log('Failed to initialize WebSocket: $e');
    }
  }

  Future<void> _reconnect() async {
    log('Attempting WebSocket reconnection...');
    await _channel.sink.close();
    _isConnected = false;
    // Optionally, you can trigger a reconnection attempt
  }

  void sendMessage(String message) {
    if (_isConnected) {
      _channel.sink.add(message);
    } else {
      log('WebSocket is not connected');
    }
  }

  void close() {
    _channel.sink.close();
    _isConnected = false;
  }

  void _handleServerMessage(String data) {
    // Handle incoming data
  }
}
