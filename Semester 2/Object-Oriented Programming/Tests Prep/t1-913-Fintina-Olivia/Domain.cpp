//
// Created by theo on 26.04.2023.
//

#include "Domain.h"

Player::Player() {
    this->nameOfPlayer = "";
    this->nationalityOfPlayer = "";
    this->teamOfPlayer = "";
    this->numberOfGoals = 0;
}

Player::Player(const std::string& nameOfPlayer,
               const std::string& nationalityOfPlayer,
               const std::string& teamOfPlayer,
               int numberOfGoals) {
    this->nameOfPlayer = nameOfPlayer;
    this->nationalityOfPlayer = nationalityOfPlayer;
    this->teamOfPlayer = teamOfPlayer;
    this->numberOfGoals = numberOfGoals;
}

Player::~Player() = default;

std::string Player::getNameOfPlayer() const {
    return this->nameOfPlayer;
}

std::string Player::getTeamOfPlayer() const {
    return this->teamOfPlayer;
}

int Player::getNumberOfGoals() const {
    return this->numberOfGoals;
}

std::string Player::toString() {
    std::string result = this->nameOfPlayer + " " \
    + this->nationalityOfPlayer + " " \
    + this->teamOfPlayer + " " \
    + std::to_string(this->numberOfGoals);
    return result;
}
