package com.server.server;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import jakarta.websocket.*;
import jakarta.websocket.server.ServerEndpoint;

import java.io.IOException;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

@SpringBootApplication
public class ServerApplication {

	private static final Set<Session> CLIENTS = Collections.synchronizedSet(new HashSet<>());

	public static void main(String[] args) {
		SpringApplication.run(ServerApplication.class, args);
	}

}
