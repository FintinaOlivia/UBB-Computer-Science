//
// Created by theo on 25.04.2023.
//

#include <algorithm>
#include <iostream>
#include "Controller.h"

Controller::Controller() {
    this->repository = Repository();
    this->listOfCars = repository.getAllCars();
}

Controller::Controller(Repository repository) {
    this->repository = repository;
    this->listOfCars = repository.getAllCars();
}

Controller::~Controller() = default;

bool Controller::addCar(const Car &car) {
    /*
     * Check if the car already exists in the repository
     * If it does, return false
     * If it doesn't, add it to the repository and return true
     */
    for (auto &iteratedCar : this->repository.getAllCars()) {
        if (iteratedCar.getManufacturer() == car.getManufacturer() &&
            iteratedCar.getModel() == car.getModel()) {
            return false;
        }
    }
    return this->repository.addCar(car);
}

bool Controller::removeCar(const Car &car) {
    std::cout << "Controller::removeCar" << std::endl;
    for (auto iteratedCar = this->repository.getAllCars().begin();
         iteratedCar != this->repository.getAllCars().end(); iteratedCar++) {

        if (*iteratedCar == car) {
            this->repository.removeCar(*iteratedCar);
            return true;
        }
    }
    return false;
}

bool Controller::updateCar(const Car &car, const Car &newCar) {
    for (auto &iteratedCar : this->repository.getAllCars()) {
        if (iteratedCar == car) {
            iteratedCar = newCar;
            return true;
        }
    }
    return false;
}

std::vector<Car> Controller::getAllCars() {
    return this->repository.getAllCars();
}

Car Controller::getCar(const std::string &manufacturer, const std::string &model) {
    for (auto &iteratedCar : this->repository.getAllCars()) {
        if (iteratedCar.getManufacturer() == manufacturer &&
            iteratedCar.getModel() == model) {
            return iteratedCar;
        }
    }
    return {};
}

void sortByColour(std::vector<Car> &listOfCars) {
    std::sort(listOfCars.begin(), listOfCars.end(),
              [](const Car &car1, const Car &car2) {
                  return car1.getColor() < car2.getColor();
              });
}

std::vector<Car> Controller::getVintageCarsOlderThan(int yearOfFabrication) {
    /*
     * Get all cars older than the given year of fabrication
     * Sort them by colour
     * Return the sorted list
     */
    std::vector<Car> vintageCars;
    for (auto &iteratedCar : this->repository.getAllCars()) {
        if (iteratedCar.getYearOfFabrication() < yearOfFabrication) {
            vintageCars.push_back(iteratedCar);
        }
    }
    sortByColour(vintageCars);
    return vintageCars;
}

