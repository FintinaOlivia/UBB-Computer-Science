//
// Created by Th on 23/05/2023.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>
#include "Controller.h"

Controller::Controller(Repository &repository) : repository(repository) {
    this->repository = Repository();
    this->cars = this->repository.getAll();
}

Controller::~Controller() = default;

void Controller::sortByManufacturer() {
    std::sort(this->cars.begin(), this->cars.end(), [](Car a, Car b) {
        return a.getManufacturer() < b.getManufacturer();
    });
}

std::vector<Car> Controller::filterByManufacturer(const std::string& manufacturer) {
    std::vector<Car> filtered;
    std::copy_if(this->cars.begin(), this->cars.end(), std::back_inserter(filtered), [manufacturer](Car c) {
        return c.getManufacturer() == manufacturer;
    });
    return filtered;
}

int Controller::getNumberOfCarsByManufacturer(const std::string& manufacturer) {
    /*
     * Function retrieves the number of cars with the same manufacturer
     * by checking each entity in the list
     *
     * Input:
     * - (string) manufacturer : user input string representing the
     *                          desired manufacturer
     * Output:
     * - (int) count : the number of cars fitting the criteria
     */
    int count = 0;
    for (Car car : this->cars) {
        if (car.getManufacturer() == manufacturer) {
            count++;
        }
    }
    return count;
}

std::vector<Car> Controller::getAll() {
    this->sortByManufacturer();
    return this->cars;
}

void test_getNumberOfCarsByManufacturer(){
    Repository fake_repository;
    Controller controller(fake_repository);

    fake_repository.addCar(Car("Audi", "A4", 2012, "red"));
    fake_repository.addCar(Car("Hyundai", "i30", 2015, "blue"));
    fake_repository.addCar(Car("Hyundai", "i20", 2019, "yellow"));
    fake_repository.addCar(Car("Mercedes", "C-Class", 2018, "black"));

    assert(controller.getNumberOfCarsByManufacturer("Audi") == 1);
}