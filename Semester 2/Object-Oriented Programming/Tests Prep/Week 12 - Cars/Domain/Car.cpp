#include <vector>
#include <cstring>
#include <sstream>
#include "Car.h"

Car::Car() {
    this->manufacturer = "";
    this->model = "";
    this->yearOfFabrication = 0;
    this->colour = "";
}

Car::Car(std::string manufacturer, std::string model, int yearOfFabrication, std::string colour) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->yearOfFabrication = yearOfFabrication;
    this->colour = colour;
}

Car::~Car() = default;

std::string Car::getManufacturer() {
    return this->manufacturer;
}

std::string Car::getModel() {
    return this->model;
}

int Car::getYearOfFabrication() {
    return this->yearOfFabrication;
}

std::string Car::getColour() {
    return this->colour;
}

bool Car::operator==(const Car &car) {
    return this->manufacturer == car.manufacturer && this->model == car.model &&
           this->yearOfFabrication == car.yearOfFabrication && this->colour == car.colour;
}

std::istream &operator>>(std::istream &is, Car &car) {
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 4) {
        return is;
    }

    car.manufacturer = tokens[0];
    car.model = tokens[1];
    car.yearOfFabrication = stoi(tokens[2]);
    car.colour = tokens[3];

    return is;
}

std::ostream &operator<<(std::ostream &os, Car &car) {
    os << car.manufacturer << "|" << car.model << "|" << car.yearOfFabrication << "|" << car.colour;
    return os;
}

std::string Car::toString() {
    return "Manufacturer: " + this->manufacturer + " | Model: " + this->model;
}

