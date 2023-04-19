#pragma once 
#include <string>
#include <iostream>
#include "Controller.h"
#include "Domain.h"
#include "DynamicArray.h"
#include "Repository.h"

class UI
{
    private:
        Controller basket_controller;
        Controller controller;

    public:
        UI(Controller controller, Controller basket_controller);
        void printWelcomeMessage();
        void printAdminMenu();

        void printAllTrenchCoats(int codeOfController);
        void printGoodbyeMessage();
        void printQuestioningMessage();
        void printUserMenu();
        void printPurchaseMessage();
        void printUserBrowsingMenu();
        void printAddToCartButton();
        void printTrenchCoat(TrenchCoat trenchCoatToPrint);

        void administratorMode();
        void userMode();

        void runApplication();

        void addTrenchCoat();
        void removeTrenchCoat();
        void updateTrenchCoat();
        void getTrenchCoat();
        void writeToDatabase();
        void readFromDatabase();

        void cycleThroughTrenchCoats();
        void addTrenchCoatToShoppingBasket(TrenchCoat trenchCoatToAdd);
        void removeTrenchCoatFromShoppingBasket(int trenchID);
        void printShoppingBasket();
        void emptyBasketOfTrenchCoats();

};