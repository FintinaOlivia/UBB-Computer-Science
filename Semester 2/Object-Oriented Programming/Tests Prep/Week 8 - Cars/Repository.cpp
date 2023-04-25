//
// Created by theo on 25.04.2023.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "Repository.h"
#include "Domain.h"

Repository::Repository() {
    this->allCars = std::vector<Car>();
}

Repository::~Repository() = default;

bool Repository::addCar(const Car& car) {
    for (auto &iteratedCar : this->allCars) {
        if (iteratedCar == car) {
            return false;
        }
    }
    this->allCars.push_back(car);
    sortCarsByManufacturerAndModel(this->allCars);
    return true;
}

bool Repository::removeCar(const Car& car) {
    std::cout << "Repository::removeCar" << std::endl;
    for (auto iteratedCar = this->allCars.begin();
            iteratedCar != this->allCars.end(); iteratedCar++) {
        if (*iteratedCar == car) {
            this->allCars.erase(iteratedCar);
            return true;
        }
    }
    return false;
}

bool Repository::updateCar(const Car& car, const Car& newCar) {
    for (auto & allCar : this->allCars) {
        if (allCar == car) {
            allCar = car;
            return true;
        }
    }
    return false;
}

std::vector<Car> Repository::getAllCars() {
    return this->allCars;
}

Car Repository::getCar(const std::string& manufacturer, const std::string& model) {
    for (auto &iteratedCar : this->allCars) {
        if (iteratedCar.getManufacturer() == manufacturer &&
                iteratedCar.getModel() == model) {
            return iteratedCar;
        }
    }
    return {};
}

void Repository::sortCarsByManufacturerAndModel(std::vector<Car> &listOfCars) {
    std::sort(listOfCars.begin(), listOfCars.end(),
              [](const Car &car1, const Car &car2) {
                  if (car1.getManufacturer() == car2.getManufacturer()) {
                      return car1.getModel() < car2.getModel();
                  }
                  return car1.getManufacturer() < car2.getManufacturer();
              });
}

