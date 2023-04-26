//
// Created by theo on 26.04.2023.
//

#include "Controller.h"

Controller::Controller() {
    this->repository = Repository();
}

Controller::Controller(Repository repository) {
    this->repository = repository;
}

Controller::~Controller() = default;


bool Controller::addPlayer(const Player &player) {
    /*
     * This function adds a player to the repository.
     * Input: player - Player
     * Output: true - if the player was added
     *        false - if the player was not added
     *        (the player already exists in the repository)
     */

    for(auto &playerToBeAdded : this->repository.getAllPlayers()) {
        if (playerToBeAdded.getNameOfPlayer() == player.getNameOfPlayer()) {
            return false;
        }
    }
    return this->repository.addPlayer(player);
}

std::vector<Player> Controller::getAllPlayers() {
    return this->repository.getAllPlayers();
}

int Controller::getNumberOfPlayers() {
    return this->repository.getNumberOfPlayers();
}

std::vector<Player> Controller::getPlayersByTeam(const std::string &team) {
    /*
     * This function returns all the players from a team, after sorting them
     * by the number of goals.
     *
     * Input: team - std::string
     * Output: playersByTeam - std::vector<Player>
     *
     */
    std::vector<Player> playersByTeam;
    for (auto &player : this->repository.getAllPlayers()) {
        if (player.getTeamOfPlayer() == team) {
            playersByTeam.push_back(player);
        }
    }
    sortPlayersByNumberOfGoals(playersByTeam);
    return playersByTeam;
}

void Controller::sortPlayersByNumberOfGoals(std::vector<Player> &players) {
    /*
     * This function sorts the players by the number of goals.
     * Input: players - std::vector<Player>
     * Output: the players are sorted by the number of goals
     */

    for (int i = 0; i < players.size() - 1; i++) {
        for (int j = i + 1; j < players.size(); j++) {
            if (players[i].getNumberOfGoals() < players[j].getNumberOfGoals()) {
                Player aux = players[i];
                players[i] = players[j];
                players[j] = aux;
            }
        }
    }
}

Player Controller::getPlayer(const std::string &nameOfPlayer) {
    for (auto &player : this->repository.getAllPlayers()) {
        if (player.getNameOfPlayer() == nameOfPlayer) {
            return player;
        }
    }
    return {};
}


int Controller::getTotalNumberOfGoals(std::vector<Player> players) {
    int totalNumberOfGoals = 0;
    for (auto && player : players) {
        totalNumberOfGoals += player.getNumberOfGoals();
    }
    return totalNumberOfGoals;
}

