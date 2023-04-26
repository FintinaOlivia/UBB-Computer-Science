//
// Created by theo on 26.04.2023.
//

#include "Tests.h"
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include <cassert>
#include <iostream>

void Tests::testAddPlayer() {
    Repository repository;
    repository.addPlayer(Player("Theo", "Romania", "Manchester United", 10));
    assert(repository.getNumberOfPlayers() == 1);
    assert(repository.addPlayer(Player("Theo", "Romania", "Manchester United", 10)) == false);
    assert(repository.getNumberOfPlayers() == 1);
}

void Tests::testGetPlayersByTeam() {
    Repository repository;
    Controller controller(repository);
    repository.addPlayer(Player("Theo", "Romania", "Manchester United", 20));
    repository.addPlayer(Player("Ilie", "Romania", "Manchester United", 10));
    repository.addPlayer(Player("Alex", "Romania", "Baiern Munchen", 10));

    std::vector<Player> playersByTeam = controller.getPlayersByTeam("Manchester United");
    assert(playersByTeam.size() == 2);
    assert(playersByTeam[0].getNameOfPlayer() == "Theo");
    assert(playersByTeam[1].getNameOfPlayer() == "Ilie");
    int totalNumberOfGoals = controller.getTotalNumberOfGoals(playersByTeam);
    assert(totalNumberOfGoals == 30);
    std::cout << "All tests passed!" << std::endl;
}

