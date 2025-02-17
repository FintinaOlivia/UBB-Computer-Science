package com.server.server.Socket;


import org.springframework.web.socket.*;
import org.springframework.web.socket.handler.TextWebSocketHandler;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class WebSocketServer extends TextWebSocketHandler {
    private static final Set<WebSocketSession> CLIENTS = Collections.synchronizedSet(new HashSet<>());

    @Override
    public void afterConnectionEstablished(WebSocketSession session) throws Exception {
        CLIENTS.add(session);
        System.out.println("WebSocket client connected: " + session.getId());
    }

    @Override
    public void handleTextMessage(WebSocketSession session, TextMessage message) throws Exception {
        System.out.println("Received message from client " + session.getId() + ": " + message.getPayload());
    }

    @Override
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) throws Exception {
        CLIENTS.remove(session);
        System.out.println("WebSocket client disconnected: " + session.getId());
    }

    @Override
    public void handleTransportError(WebSocketSession session, Throwable exception) throws Exception {
        CLIENTS.remove(session);
        System.err.println("WebSocket error for client " + session.getId() + ": " + exception.getMessage());
    }

    public static void broadcast(String message) {
        synchronized (CLIENTS) {
            for (WebSocketSession client : CLIENTS) {
                try {
                    client.sendMessage(new TextMessage(message));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
