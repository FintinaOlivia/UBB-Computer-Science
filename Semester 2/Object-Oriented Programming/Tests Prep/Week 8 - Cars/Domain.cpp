//
// Created by theo on 25.04.2023.
//

#include "Domain.h"

#include <utility>

Car::Car() {
    this->manufacturer = "";
    this->model = "";
    this->yearOfFabrication = 0;
    this->color = "";
}

Car::Car(std::string manufacturer, std::string model,
         int yearOfFabrication, std::string color) {
    this->manufacturer = std::move(manufacturer);
    this->model = std::move(model);
    this->yearOfFabrication = yearOfFabrication;
    this->color = std::move(color);
}

const std::string &Car::getManufacturer() const {
    return manufacturer;
}

void Car::setManufacturer(const std::string &manufacturer) {
    Car::manufacturer = manufacturer;
}

const std::string &Car::getModel() const {
    return model;
}

void Car::setModel(const std::string &model) {
    Car::model = model;
}

int Car::getYearOfFabrication() const {
    return yearOfFabrication;
}

void Car::setYearOfFabrication(int yearOfFabrication) {
    Car::yearOfFabrication = yearOfFabrication;
}

const std::string &Car::getColor() const {
    return color;
}

void Car::setColor(const std::string &color) {
    Car::color = color;
}

bool Car::operator==(const Car &rhs) const {
    return manufacturer == rhs.manufacturer &&
           model == rhs.model &&
           yearOfFabrication == rhs.yearOfFabrication &&
           color == rhs.color;
}

bool Car::operator!=(const Car &rhs) const {
    return !(rhs == *this);
}

std::string Car::toString() {
    return "Manufacturer: " + this->manufacturer + " | "\
             "Model: " + this->model + " | "\
              "Year of fabrication: " + std::to_string(this->yearOfFabrication) + " | "\
              "Color: " + this->color;
}

