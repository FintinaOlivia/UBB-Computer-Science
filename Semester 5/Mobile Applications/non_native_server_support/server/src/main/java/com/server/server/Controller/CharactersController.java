package com.server.server.Controller;


import com.server.server.Repository.CharacterRepository;
import com.server.server.Model.Character;
import com.server.server.Socket.CharacterSyncRequest;
import com.server.server.Socket.WebSocketServer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.*;
import org.springframework.beans.factory.annotation.Autowired;
import java.util.List;

@RestController
@RequestMapping("/characters")
public class CharactersController {
    private static final Logger logger = LoggerFactory.getLogger(CharactersController.class);

    @Autowired
    private CharacterRepository characterRepository;

    @GetMapping("/")
    public String check() {
        return "SUCCESS";
    }

    @GetMapping
    public List<Character> getCharacters() {
        logger.info("Fetching all characters");
        return characterRepository.findAll();
    }

    @PostMapping("/sync")
    public List<Character> syncCharacters(@RequestBody CharacterSyncRequest request) {
        logger.info("Syncing characters with request: {}", request);
        List<Character> currentCharacters = characterRepository.findAll();

        if(request.getDeletedIds() != null) {
            logger.debug("Deleted IDs: {}", request.getDeletedIds());
            request.getDeletedIds().forEach(characterRepository::deleteById);
        }

        if(request.getUpdatedCharacters() != null) {
            logger.debug("Updated characters: {}", request.getUpdatedCharacters());
            characterRepository.saveAll(request.getUpdatedCharacters());
        }

        if(request.getNewCharacters() != null) {
            logger.debug("New characters: {}", request.getNewCharacters());
            for (Character newCharacter : request.getNewCharacters()) {
                boolean exists = currentCharacters.stream()
                        .anyMatch(c -> c.equals(newCharacter)
                                || c.getCharacterId().equals(newCharacter.getCharacterId()));
                if (!exists) {
                    logger.info("Adding new character: {}", newCharacter);
                    characterRepository.save(newCharacter);
                }
            }
        }
        return characterRepository.findAll();
    }

    @GetMapping("/{id}")
    public Character getCharacter(@PathVariable String id) {
        logger.info("Fetching character with ID: {}", id);
        return characterRepository.findById(id).orElseThrow(() -> {
            logger.error("Character not found with ID: {}", id);
            return new RuntimeException("Character not found");
        });
    }

    @PostMapping
    public String addCharacter(@RequestBody Character character) {
        logger.info("Adding character: {}", character);
        characterRepository.save(character);
        WebSocketServer.broadcast("ADD$" + character.toJson());
        return "SUCCESS";
    }

    @PutMapping
    public String updateCharacter(@RequestBody Character character) {
        logger.info("Updating character: {}", character);
        characterRepository.save(character);
       WebSocketServer.broadcast("UPDATE$" + character.toJson());
        return "SUCCESS";
    }

    @DeleteMapping("/{id}")
    public String deleteCharacter(@PathVariable String id) {
        logger.info("Deleting character with ID: {}", id);
        characterRepository.deleteById(id);
        WebSocketServer.broadcast("DELETE$" + id);
        return "SUCCESS";
    }
}
