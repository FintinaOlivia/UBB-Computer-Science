//
// Created by theo on 25.04.2023.
//

#ifndef UNTITLED_REPOSITORY_H
#define UNTITLED_REPOSITORY_H


#include "Domain.h"

class Repository {
private:
    std::vector<Car> allCars;
public:
    Repository();
    ~Repository();

    bool addCar(const Car& car);
    bool removeCar(const Car&  car);
    bool updateCar(const Car&  car, const Car&  newCar);

    static void sortCarsByManufacturerAndModel(std::vector<Car> &listOfCars);

    std::vector<Car> getAllCars();
    Car getCar(const std::string& manufacturer, const std::string& model);
};


#endif //UNTITLED_REPOSITORY_H
