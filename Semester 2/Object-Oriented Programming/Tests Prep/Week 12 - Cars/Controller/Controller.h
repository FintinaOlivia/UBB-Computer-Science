//
// Created by Th on 23/05/2023.
//

#ifndef T3_CARS_CONTROLLER_H
#define T3_CARS_CONTROLLER_H


#include "../Repository/Repository.h"

class Controller {
private:
    Repository& repository;
    std::vector<Car> cars;

public:
    explicit Controller(Repository &repository);
    ~Controller();

    std::vector<Car> getAll();
    void sortByManufacturer();
    std::vector<Car> filterByManufacturer(const std::string& manufacturer);
    int getNumberOfCarsByManufacturer(const std::string& manufacturer);

};

void test_getNumberOfCarsByManufacturer();

#endif //T3_CARS_CONTROLLER_H
