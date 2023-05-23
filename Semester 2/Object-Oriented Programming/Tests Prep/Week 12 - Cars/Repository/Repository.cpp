//
// Created by Th on 23/05/2023.
//

#include <fstream>
#include "Repository.h"

Repository::Repository() {
    this->LoadData();
}

Repository::~Repository() = default;

std::vector<Car> Repository::getAll() {
    return this->elements;
}

void Repository::LoadData() {
    std::ifstream inFile(R"(C:\Users\Th\CLionProjects\T3-Cars\input.txt)");
    Car CurrentElement;
    this->elements.clear();
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
    inFile.close();
}

void Repository::addCar(const Car &car) {
    this->elements.push_back(car);
}
