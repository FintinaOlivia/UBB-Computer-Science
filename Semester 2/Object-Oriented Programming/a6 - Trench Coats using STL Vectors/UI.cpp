#include "UI.h"
#include <string>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;
#define MAX_NAME_LEN 60

//Constructor
UI::UI(Controller controller, Controller basket_controller)
{
    this->controller = std::move(controller);
    this->basket_controller = std::move(basket_controller);
}

//Prints
void UI::printWelcomeMessage()
{
    std::cout << "Welcome to the Administration ProperTrenchCoat application!" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
}

void UI::printQuestioningMessage()
{
    std::cout << std::endl;
    std::cout << "================WELCOME TO THE PROPER TRENCH COATS!===============" << std::endl;
    std::cout << "Hello and welcome to the Proper Trench Coats! You want it, we got it!" << std::endl;
    std::cout << "Are you here as administrator(1) or as user(2)? Press (0) to exit...\n >";
}

void UI::printAddToCartButton(){
    std::cout << "            ================              " << std::endl;
    std::cout << "            =  Add to cart =              " << std::endl;
    std::cout << "            ================              " << std::endl;
    std::cout << std::endl;
}

void UI::printTrenchCoat(TrenchCoat trenchCoatToPrint)
{
    std::cout << std::endl;
    std::cout << "ID: " << trenchCoatToPrint.getTrenchID() << std::endl;
    std::cout << "Size: " << trenchCoatToPrint.getTrenchSize() << std::endl;
    std::cout << "Colour: " << trenchCoatToPrint.getTrenchColour() << std::endl;
    std::cout << "Price: " << trenchCoatToPrint.getTrenchPrice() << std::endl;
    std::cout << "Quantity: " << trenchCoatToPrint.getTrenchQuantity() << std::endl;
    std::cout << "Photograph: " << trenchCoatToPrint.getTrenchPhotographyLink() << std::endl;
    std::cout << std::endl;
}

//Admin menu
void UI::printAdminMenu()
{
    std::cout << std::endl;
    std::cout << "===========ADMINISTRATOR MODE============" << std::endl;
    std::cout << "1. Add a trench coat" << std::endl;
    std::cout << "2. Remove a trench coat" << std::endl;
    std::cout << "3. Update a trench coat" << std::endl;
    std::cout << "4. Get a trench coat" << std::endl;
    std::cout << "5. Print all trench coats" << std::endl;
    std::cout << "6. Write to database" << std::endl;
    std::cout << "7. Read from database" << std :: endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "=========================================" << std::endl << std::endl;
    std::cout << "> ";
}

void UI::printAllTrenchCoats(int codeOfController)
{
    if(codeOfController == 1){
        std::vector<TrenchCoat> allTrenchCoats =
                this->controller.getAllTrenchCoats();

        
        for (int i = 0; i < allTrenchCoats.size(); i++)
        {
            printTrenchCoat(allTrenchCoats[i]);
        }
    }else{
        std::vector<TrenchCoat> allTrenchCoats =
                this->basket_controller.getAllTrenchCoats();

            
        for (int i = 0; i < allTrenchCoats.size(); i++)
        {
            
            TrenchCoat trenchCoat = allTrenchCoats[i];
            std::cout << "ID: " << trenchCoat.getTrenchID() << " || " 
                    << "Size: " << trenchCoat.getTrenchSize() << " || " 
                    << "Colour: " << trenchCoat.getTrenchColour() << " || "
                    << "Price: " << trenchCoat.getTrenchPrice() << " || " 
                    << "Quantity: " << trenchCoat.getTrenchQuantity() << " || " 
                    << "Link: " << trenchCoat.getTrenchPhotographyLink() 
                    << std::endl;
        }
    }
}

//User menu
void UI::printUserMenu(){
    std::cout << std::endl;
    std::cout << "===========USER MODE============" << std::endl;
    std::cout << "1. Browse through all trench coats" << std::endl;
    std::cout << "2. Display all trench coats in the shopping cart" << std::endl;
    std::cout << "3. Purchase all trench coats in the shopping cart" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "=========================================" << std::endl << std::endl;
    std::cout << "> ";
}

void UI::printUserBrowsingMenu(){
    std::cout << std::endl;
    std::cout << "Enter 1 to go the previous trench coat, ";
    std::cout << "2 to go to the next trench coat, ";
    std::cout << "3 to add the trench coat to the shopping basket, ";
    std::cout << "and 4 to exit the cycle." << std::endl;
    std::cout << "Happy shopping!> " << std::endl;
}

void UI::printPurchaseMessage()
{
    std::cout << "Thank you for your purchase!" << std::endl;
}

void UI::printGoodbyeMessage()
{
    std::cout << "Goodbye!" << std::endl;
}

//Admin Mode Functions
void UI::administratorMode()
{
    this->printWelcomeMessage();
    this->printAdminMenu();
    int command;
    std::cin >> command;
    while (command < 9 && command > 0)
    {
        switch (command)
        {
        case 1:
            this->addTrenchCoat();
            break;
        case 2:
            this->removeTrenchCoat();
            break;
        case 3:
            this->updateTrenchCoat();
            break;
        case 4:
            this->getTrenchCoat();
            break;
        case 5:
            this->printAllTrenchCoats(1);
            break;
        case 6:
            this->writeToDatabase();
            std::cout << "Writing to database..." << std::endl;
            break;
        case 7:
            this->readFromDatabase();
            break;
        case 8:
            this->printGoodbyeMessage();
            return;

        default:
            std::cout << "Invalid command!" << std::endl;
            break;
        }
        this->printAdminMenu();
        std::cin >> command;
    }
    this->printGoodbyeMessage();
}

void UI::addTrenchCoat()
{
    int id, sizeOfTrench, quantityOfTrench;
    char colourOfTrench[MAX_NAME_LEN], photography_linkOfTrench[MAX_NAME_LEN];
    float priceOfTrench;

    std::cout << "Enter the ID of the trench coat: ";
    std::cin >> id;

    while(id <= 0){
        std::cout << "The ID must be a positive integer!" << std::endl;
        std::cout << "Enter the ID of the trench coat: ";
        std::cin >> id;
    }

    std::cout << "Enter the size of the trench coat: ";
    std::cin >> sizeOfTrench;

    while(sizeOfTrench <= 30 || sizeOfTrench >= 50){
        std::cout << "The size must be in the range [30,60]!" << std::endl;
        std::cout << "Enter the size of the trench coat: ";
        std::cin >> sizeOfTrench;
    }

    std::cout << "Enter the colour of the trench coat: ";
    std::cin >> colourOfTrench;

    std::cout << "Enter the price of the trench coat: ";
    std::cin >> priceOfTrench;

    while(priceOfTrench <= 0){
        std::cout << "The price must be a positive number!" << std::endl;
        std::cout << "Enter the price of the trench coat: ";
        std::cin >> priceOfTrench;
    }

    std::cout << "Enter the quantity of the trench coat: ";
    std::cin >> quantityOfTrench;

    while(quantityOfTrench <= 0){
        std::cout << "The quantity must be a positive integer!" << std::endl;
        std::cout << "Enter the quantity of the trench coat: ";
        std::cin >> quantityOfTrench;
    }

    std::cout << "Enter the photography link of the trench coat: ";
    std::cin >> photography_linkOfTrench;
                            
    std:: cout << "Adding trench coat..." << std::endl;
 
    if(this->controller.addTrenchCoat(id, 
                            sizeOfTrench, 
                            colourOfTrench, 
                            priceOfTrench, 
                            quantityOfTrench, 
                            photography_linkOfTrench)){
        std :: cout << "Trench coat added!" << std::endl;
    }else{
        std:: cout << "Trench coat with this ID already exists!" << std::endl;
    }
}

void UI::removeTrenchCoat()
{
    int id;
    std::cout << "Enter the ID of the trench coat you want to remove: ";
    std::cin >> id;

    while(id <= 0){
        std::cout << "The ID must be a positive integer!" << std::endl;
        std::cout << "Enter the ID of the trench coat you want to remove: ";
        std::cin >> id;
    }

    if(!this->controller.trenchCoatExists(id)){
        std::cout << ("The trench coat does not exist!") << std::endl;
    }else{
        std::cout << "Removing trench coat..." << std::endl;
        this->controller.removeTrenchCoat(id);
        std::cout << "Trench coat removed!" << std::endl;
    }
}

void UI::updateTrenchCoat()
{
    int id, newID, sizeOfTrench, quantityOfTrench;
    std::string colourOfTrench, photography_linkOfTrench;
    float priceOfTrench;

    std::cout << "Enter the ID of the trench coat: ";
    std::cin >> id;
    
    if(!this->controller.trenchCoatExists(id)){
        std::cout << ("The trench coat does not exist!") << std::endl;
    }else{
        std::cout << "Enter the new ID of the trench coat: ";
        std::cin >> newID;

        if(this->controller.trenchCoatExists(id) > 1){
            std::cout << ("There already is a trench coat with that ID!") << std::endl;
        }else{
            while(id <= 0){
                std::cout << "The ID must be a positive integer!" << std::endl;
                std::cout << "Enter the ID of the trench coat: ";
                std::cin >> newID;
            }

            std::cout << "Enter the size of the trench coat: ";
            std::cin >> sizeOfTrench;

            while(sizeOfTrench <= 30 || sizeOfTrench >= 50){
                std::cout << "The size must be in the range [30,60]!" << std::endl;
                std::cout << "Enter the size of the trench coat: ";
                std::cin >> sizeOfTrench;
            }

            std::cout << "Enter the colour of the trench coat: ";
            std::cin >> colourOfTrench;

            std::cout << "Enter the price of the trench coat: ";
            std::cin >> priceOfTrench;

            while(priceOfTrench <= 0){
                std::cout << "The price must be a positive number!" << std::endl;
                std::cout << "Enter the price of the trench coat: ";
                std::cin >> priceOfTrench;
            }

            std::cout << "Enter the quantity of the trench coat: ";
            std::cin >> quantityOfTrench;

            while(quantityOfTrench <= 0){
                std::cout << "The quantity must be a positive integer!" << std::endl;
                std::cout << "Enter the quantity of the trench coat: ";
                std::cin >> quantityOfTrench;
            }

            std::cout << "Enter the photography link of the trench coat: ";
            std::cin >> photography_linkOfTrench;

            std:: cout << "Updating trench coat..." << std::endl;
            this->controller.updateTrenchCoat(id, 
                                    newID, 
                                    sizeOfTrench, 
                                    colourOfTrench, 
                                    priceOfTrench, 
                                    quantityOfTrench, 
                                    photography_linkOfTrench);
        }
    }
}

void UI::getTrenchCoat()
{
    int id;
    std::cout << "Enter the ID of the trench coat you want to get: ";
    std::cin >> id;

    while(id <= 0){
        std::cout << "The ID must be a positive integer!" << std::endl;
        std::cout << "Enter the ID of the trench coat you want to get: ";
        std::cin >> id;
    }

    if(!this->controller.trenchCoatExists(id)){
        std::cout << ("The trench coat does not exist!") << std::endl;
    }else{
        std::cout << "Getting trench coat..." << std::endl;
        this->controller.getTrenchCoat(id);
        std::cout << "The Trench Coat! Is here!" << std::endl;
    }
}

void UI::writeToDatabase(){
    this->controller.saveProgress();
}

void UI::readFromDatabase(){
    this->controller.loadFromFile();
    std::cout << "The database has been loaded!" << std::endl;
}

//User Mode Functions
void UI::cycleThroughTrenchCoats()
{
    int sizeToFilterBy, totalCost = 0;
    std::cout << "Enter the size of the trench coats you want to see,";
    std::cout << " or press 0 to see all trench coats1> " << std::endl;
    std::cin >> sizeToFilterBy;

    int index = 0;
    int command;
    this->printUserBrowsingMenu();

    std::vector<TrenchCoat> trenchCoats;

    if(sizeToFilterBy != 0){    
        trenchCoats = this->controller.filterBySize(sizeToFilterBy);
    }else{
        trenchCoats = this->controller.getAllTrenchCoats();
    }

    std::cin >> command;
    if(trenchCoats.size() == 0){
        std::cout << "There are no trench coats with that size!" << std::endl;
        return;
    }else{
        while(command != 4){
            if(command == 1){
                if(index == 0){
                    index = trenchCoats.size() - 1;{
                        this->printTrenchCoat(trenchCoats[index]);
                        std::string completeUrl = "https://www.google.com/search?q=" + trenchCoats[index].getTrenchPhotographyLink();
                        system(std::string("start " + completeUrl).c_str());
                        this->printAddToCartButton();
                    }
                }else{
                    index--;{
                        this->printTrenchCoat(trenchCoats[index]);
                        this->printAddToCartButton();
                    }
                }
            }else if(command == 2){
                if(index == trenchCoats.size() - 1){
                    index = 0;{
                        this->printTrenchCoat(trenchCoats[index]);
                        this->printAddToCartButton();
                    }
                }else{
                    index++;
                    {
                        this->printTrenchCoat(trenchCoats[index]);
                        this->printAddToCartButton();
                    }
                }
            }else if(command == 3){
                this->addTrenchCoatToShoppingBasket(trenchCoats[index]);
                std::cout << "Trench coat added to the shopping basket!" << std::endl;
                totalCost += trenchCoats[index].getTrenchPrice();
                std::cout << "Total cost: " << totalCost << std::endl;
            }else{
                std::cout << "Invalid command!" << std::endl;
            }
            std::cout << "> ";
            std::cin >> command;
        }
    }
}

void UI::addTrenchCoatToShoppingBasket(TrenchCoat trenchCoatToAdd)
{
    this->basket_controller.addTrenchCoat(trenchCoatToAdd.getTrenchID(),
                                          trenchCoatToAdd.getTrenchSize(),
                                          trenchCoatToAdd.getTrenchColour(),
                                          trenchCoatToAdd.getTrenchPrice(),
                                          trenchCoatToAdd.getTrenchQuantity(),
                                          trenchCoatToAdd.getTrenchPhotographyLink());
}

/*
void UI::removeTrenchCoatFromShoppingBasket(int trenchCoatID)
{
    this->basket_controller.removeTrenchCoat(trenchCoatID);
}
*/

void UI::printShoppingBasket()
{
    int totalCost = 0;
    std::vector<TrenchCoat> shoppingBasket = this->basket_controller.getAllTrenchCoats();
    for(auto & i : shoppingBasket){
        this->printTrenchCoat(i);
        totalCost += i.getTrenchPrice();
    }
    std::cout << "Total cost: " << totalCost << std::endl;
}

void UI::emptyBasketOfTrenchCoats()
{
    std::vector<TrenchCoat> shoppingBasket = this->basket_controller.getAllTrenchCoats();
    for(int i = 0; i < shoppingBasket.size(); i++){

        this->controller.updateTrenchCoat(shoppingBasket[i].getTrenchID(),
                                            shoppingBasket[i].getTrenchID(),
                                            shoppingBasket[i].getTrenchSize(),
                                            shoppingBasket[i].getTrenchColour(),
                                            shoppingBasket[i].getTrenchPrice(),
                                            shoppingBasket[i].getTrenchQuantity() - 1,
                                            shoppingBasket[i].getTrenchPhotographyLink());

        this->basket_controller.removeTrenchCoat(shoppingBasket[i].getTrenchID());
    }
}

void UI::userMode(){
    this->printUserMenu();
    this->controller.loadFromFile();
    int command;
    std::cin >> command;

    while (command < 4 && command > 0)
    {
        switch (command)
        {
        case 1:
            this->cycleThroughTrenchCoats();
            break;
        case 2:
             this->printShoppingBasket();
            break;
        case 3:
            this->printPurchaseMessage();
            this->emptyBasketOfTrenchCoats();
            break;
        case 4:
            this->printGoodbyeMessage();
            break;
        default:
            std::cout << "Invalid command!" << std::endl;
            break;
        }
        this->printUserMenu();
        std::cin >> command;
    }
}

void UI::runApplication(){
    this->printQuestioningMessage();
    int command;
    std::cin >> command;
    while (command < 3 && command > 0)
    {
        switch (command)
        {
        case 1:
            this->administratorMode();
            break;
        case 2:
            this->userMode();
            break;
        default:
            std::cout << "Invalid command!" << std::endl;
            break;
        }
        this->printQuestioningMessage();
        std::cin >> command;
    }
    this->printGoodbyeMessage();
}

