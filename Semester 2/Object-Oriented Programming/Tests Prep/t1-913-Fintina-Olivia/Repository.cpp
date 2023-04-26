//
// Created by theo on 26.04.2023.
//

#include "Repository.h"

Repository::Repository() {
    this->listOfAllPlayers = std::vector<Player>();
    this->numberOfPlayers = 0;
}


Repository::~Repository() = default;

bool Repository::addPlayer(const Player &player) {
    for (auto &playerToBeAdded : this->listOfAllPlayers) {
        if (playerToBeAdded.getNameOfPlayer() == player.getNameOfPlayer()) {
            return false;
        }
    }
    this->listOfAllPlayers.push_back(player);
    this->numberOfPlayers++;
    return true;
}

std::vector<Player> Repository::getAllPlayers() {
    return this->listOfAllPlayers;
}

int Repository::getNumberOfPlayers() const {
    return this->numberOfPlayers;
}