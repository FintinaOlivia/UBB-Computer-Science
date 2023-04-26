//
// Created by theo on 26.04.2023.
//

#ifndef T1_913_FINTINA_OLIVIA_1_REPOSITORY_H
#define T1_913_FINTINA_OLIVIA_1_REPOSITORY_H


#include <vector>
#include "Domain.h"

class Repository {
private:
    std::vector<Player> listOfAllPlayers;
    int numberOfPlayers;

public:
    Repository();
    ~Repository();

    bool addPlayer(const Player& player);
    std::vector<Player> getAllPlayers();
    int getNumberOfPlayers() const;
};


#endif //T1_913_FINTINA_OLIVIA_1_REPOSITORY_H
