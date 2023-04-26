//
// Created by theo on 26.04.2023.
//

#include <iostream>
#include "UI.h"

UI::UI() {
    this->controller = Controller();
}

UI::UI(Controller controller) {
    this->controller = controller;
}

UI::~UI() = default;

void UI::printMenu(){
    std::cout << "1. Add a player" << std::endl;
    std::cout << "2. Print all players" << std::endl;
    std::cout << "3. Print players by team" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void UI::addPlayer() {
    std::string nameOfPlayer;
    std::string nationalityOfPlayer;
    std::string teamOfPlayer;
    int numberOfGoals;

    std::cout << "Name of player: ";
    std::cin.ignore();
    std::cin >> nameOfPlayer;


    std::cout << "Nationality of player: ";
    std::cin.ignore();
    std::cin >> nationalityOfPlayer;

    std::cout << "Team of player: ";
    std::cin.ignore();
    std::cin >> teamOfPlayer;

    std::cout << "Number of goals: ";
    std::cin >> numberOfGoals;

    Player player = Player(nameOfPlayer,
                           nationalityOfPlayer,
                           teamOfPlayer,
                           numberOfGoals);
    std::cout << player.toString() << std::endl;

    if (this->controller.addPlayer(player)) {
        std::cout << "Player added successfully!" << std::endl;
    } else {
        std::cout << "Player already exists!" << std::endl;
    }
}

void UI::printAllPlayers() {
    std::vector<Player> players = this->controller.getAllPlayers();
    for (auto &player : players) {
        std::cout << player.toString() << std::endl;
    }
}

void UI::printPlayersByTeam() {
    std::string team;

    std::cout << "Team: ";
    std::cin.ignore();
    std::cin >> team;

    std::vector<Player> players = this->controller.getPlayersByTeam(team);
    for (auto &player : players) {
        std::cout << player.toString() << std::endl;
    }
    std::cout << "Total Number of Goals: " << this->controller.getTotalNumberOfGoals(players) << std::endl;
}

void UI::runApplication() {
    std::cout << "Welcome to the European Handball Federation App!" << std::endl;
    this->initializePlayers();
    int option = 1;
    while (option != 0) {
        printMenu();
        std::cout << "Option: ";
        std::cin >> option;
        switch (option) {
            case 1:
                this->addPlayer();
                break;
            case 2:
                this->printAllPlayers();
                break;
            case 3:
                this->printPlayersByTeam();
                break;
            case 0:
                std::cout << "Bye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }
}

void UI::initializePlayers(){
    Player player1 = Player("Nora_Mork", "NOR", "Larvik", 83);
    Player player2 = Player("Isabelle_Gullden", "SWE", "CSM_Bucuresti", 80);
    Player player3 = Player("Cristina_Neagu", "ROU", "Budcnost", 90);
    Player player4 = Player("Allion_Pinteanu", "FRA", "HCM_Baia_Mare", 82);
    Player player5 = Player("Illina_Ekaterina", "RUS", "CSM_Bucuresti", 75);
    Player player6 = Player("Nerea_Pena", "ESP", "FTC", 59);

    this->controller.addPlayer(player1);
    this->controller.addPlayer(player2);
    this->controller.addPlayer(player3);
    this->controller.addPlayer(player4);
    this->controller.addPlayer(player5);
    this->controller.addPlayer(player6);

}