//
// Created by theo on 25.04.2023.
//

#include <iostream>
#include "UI.h"

UI::UI() {
    this->controller = Controller();
}

UI::UI(const Controller& controller) {
    this->controller = controller;
}

UI::~UI() = default;

void UI::printMenu(){
    std::cout << "1. Add car" << std::endl;
    std::cout << "2. Remove car" << std::endl;
    std::cout << "3. Update car" << std::endl;
    std::cout << "4. Get all cars" << std::endl;
    std::cout << "5. Get vintage cars" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void UI::run() {
    std::cout << "Welcome to the car management app!" << std::endl;
    this->initialize();
    while (true) {
        this->printMenu();
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                this->addCar();
                break;
            case 2:
                this->removeCar();
                break;
            case 3:
                this->updateCar();
                break;
            case 4:
                this->getAllCars();
                break;
            case 5:
                this->displayVintageCars();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    }
}

void UI::addCar() {
    std::cout << "Enter the manufacturer: ";
    std::string manufacturer;
    std::cin.ignore();
    std::getline(std::cin, manufacturer);

    std::cout << "Enter the model: ";
    std::string model;
    std::cin.ignore();
    std::cin >> model;

    std::cout << "Enter the year of fabrication: ";
    int yearOfFabrication;
    std::cin >> yearOfFabrication;

    std::cout << "Enter the type: ";
    std::string type;
    std::cin.ignore();
    std::cin >> type;

    Car car = Car(manufacturer, model, yearOfFabrication, type);
    if (this->controller.addCar(car)) {
        std::cout << "Car added successfully!" << std::endl;
    } else {
        std::cout << "Car already exists!" << std::endl;
    }
}

void UI::removeCar() {
    std::cout << "Enter the manufacturer: ";
    std::string manufacturer;
    std::cin >> manufacturer;

    std::cout << "Enter the model: ";
    std::string model;
    std::cin >> model;

    Car car = this->controller.getCar(manufacturer, model);

    if (this->controller.removeCar(car)) {
        std::cout << "Car removed successfully!" << std::endl;
    } else {
        std::cout << "Car does not exist!" << std::endl;
    }
}

void UI::updateCar() {
    std::cout << "Enter the manufacturer: ";
    std::string manufacturer;
    std::cin >> manufacturer;

    std::cout << "Enter the model: ";
    std::string model;
    std::cin >> model;

    Car car = this->controller.getCar(manufacturer, model);

    std::cout << "Enter the new manufacturer: ";
    std::string newManufacturer;
    std::cin >> newManufacturer;

    std::cout << "Enter the new model: ";
    std::string newModel;
    std::cin >> newModel;

    std::cout << "Enter the new year of fabrication: ";
    int newYearOfFabrication;
    std::cin >> newYearOfFabrication;

    std::cout << "Enter the new type: ";
    std::string newType;
    std::cin >> newType;

    Car newCar = Car(newManufacturer, newModel, newYearOfFabrication, newType);
    if (this->controller.updateCar(car, newCar)) {
        std::cout << "Car updated successfully!" << std::endl;
    } else {
        std::cout << "Car does not exist!" << std::endl;
    }
}

void UI::getAllCars() {
    std::vector<Car> cars = this->controller.getAllCars();
    for (Car car : cars) {
        std::cout << car.toString() << std::endl;
    }
}

void UI::displayVintageCars() {
    std::vector<Car> cars = this->controller.getVintageCarsOlderThan(1978);
    for (Car car : cars) {
        std::cout << car.toString() << std::endl;
    }
}

void UI::initialize() {
    Car car1 = Car("Audi", "A4", 1978, "Sedan");
    Car car2 = Car("Audi", "A6", 1950, "Green0");
    Car car3 = Car("Audi", "A8", 2018, "Sedan");
    Car car4 = Car("BMW", "X5", 1920, "Red");
    Car car5 = Car("BMW", "X6", 2015, "SUV");
    Car car6 = Car("Ford", "Fiesta", 2010, "Sedan");
    this->controller.addCar(car1);
    this->controller.addCar(car2);
    this->controller.addCar(car3);
    this->controller.addCar(car4);
    this->controller.addCar(car5);
    this->controller.addCar(car6);
}
