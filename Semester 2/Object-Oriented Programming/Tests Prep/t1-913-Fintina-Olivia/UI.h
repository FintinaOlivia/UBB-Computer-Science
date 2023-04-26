//
// Created by theo on 26.04.2023.
//

#ifndef T1_913_FINTINA_OLIVIA_1_UI_H
#define T1_913_FINTINA_OLIVIA_1_UI_H


#include "Controller.h"

class UI {
private:
    Controller controller;
public:
    UI();
    explicit UI(Controller controller);
    ~UI();

    void runApplication();
    void printMenu();
    void addPlayer();
    void printAllPlayers();
    void printPlayersByTeam();

    void initializePlayers();
};


#endif //T1_913_FINTINA_OLIVIA_1_UI_H
