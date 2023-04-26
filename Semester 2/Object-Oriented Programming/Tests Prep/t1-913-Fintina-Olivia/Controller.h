//
// Created by theo on 26.04.2023.
//

#ifndef T1_913_FINTINA_OLIVIA_1_CONTROLLER_H
#define T1_913_FINTINA_OLIVIA_1_CONTROLLER_H


#include "Repository.h"

class Controller {
private:
    Repository repository;
public:
    Controller();
    explicit Controller(Repository repository);
    ~Controller();

    bool addPlayer(const Player& player);

    std::vector<Player> getAllPlayers();
    int getNumberOfPlayers();
    Player getPlayer(const std::string& nameOfPlayer);

    int getTotalNumberOfGoals(std::vector<Player> players);

    std::vector<Player> getPlayersByTeam(const std::string& team);
    static void sortPlayersByNumberOfGoals(std::vector<Player>& players);
};


#endif //T1_913_FINTINA_OLIVIA_1_CONTROLLER_H
