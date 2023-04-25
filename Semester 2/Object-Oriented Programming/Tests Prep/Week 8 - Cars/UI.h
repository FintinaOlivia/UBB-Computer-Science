//
// Created by theo on 25.04.2023.
//

#ifndef UNTITLED_UI_H
#define UNTITLED_UI_H


#include "Controller.h"

class UI {
private:
    Controller controller;
public:
    UI();
    explicit UI(const Controller& controller);
    ~UI();

    void run();
    void printMenu();
    void initialize();

    void addCar();
    void removeCar();
    void updateCar();

    void getAllCars();
    void displayVintageCars();

};


#endif //UNTITLED_UI_H
