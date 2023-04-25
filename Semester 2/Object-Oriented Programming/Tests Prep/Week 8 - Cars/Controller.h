//
// Created by theo on 25.04.2023.
//

#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H


#include <vector>
#include "Domain.h"
#include "Repository.h"

class Controller {
private:
    Repository repository;
    std::vector<Car> listOfCars;
public:
    Controller();
    explicit Controller(Repository repository);
    ~Controller();

    bool addCar(const Car& car);
    bool removeCar(const Car& car);
    bool updateCar(const Car& car, const Car& newCar);

    std::vector<Car> getAllCars();
    Car getCar(const std::string& manufacturer, const std::string& model);

    std::vector<Car> getVintageCarsOlderThan(int yearOfFabrication);

};


#endif //UNTITLED_CONTROLLER_H
