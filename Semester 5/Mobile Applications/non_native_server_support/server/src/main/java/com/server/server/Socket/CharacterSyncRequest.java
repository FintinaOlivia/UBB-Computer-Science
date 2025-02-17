package com.server.server.Socket;

import lombok.Getter;

import java.util.List;
import com.server.server.Model.Character;

@Getter
public class CharacterSyncRequest {
    private List<Character> newCharacters;
    private List<String> deletedIds;
    private List<Character> updatedCharacters;

    public List<String> getDeletedIds() {
        return deletedIds;
    }

    public List<Character> getUpdatedCharacters() {
        return updatedCharacters;
    }

    public List<Character> getNewCharacters() {
        return newCharacters;
    }

}
