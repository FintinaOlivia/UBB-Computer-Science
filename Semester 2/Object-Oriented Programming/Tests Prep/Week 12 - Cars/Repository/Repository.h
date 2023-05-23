//
// Created by Th on 23/05/2023.
//

#ifndef T3_CARS_REPOSITORY_H
#define T3_CARS_REPOSITORY_H


#include <vector>
#include "../Domain/Car.h"

class Repository {
private:
    std::vector<Car> elements{};
    void LoadData();

public:
    Repository();
    ~Repository();
    void addCar(const Car& car);
    std::vector<Car> getAll();
};


#endif //T3_CARS_REPOSITORY_H
