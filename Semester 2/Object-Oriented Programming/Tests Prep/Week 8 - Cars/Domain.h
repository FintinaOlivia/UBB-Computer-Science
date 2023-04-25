//
// Created by theo on 25.04.2023.
//

#ifndef UNTITLED_DOMAIN_H
#define UNTITLED_DOMAIN_H


#include <string>

class Car {
private:
    std::string manufacturer;
    std::string model;
    int yearOfFabrication;
    std::string color;
public:
    Car();
    Car(std::string manufacturer, std::string model, int yearOfFabrication, std::string color);

    const std::string &getManufacturer() const;
    void setManufacturer(const std::string &manufacturer);

    const std::string &getModel() const;
    void setModel(const std::string &model);

    int getYearOfFabrication() const;
    void setYearOfFabrication(int yearOfFabrication);

    const std::string &getColor() const;
    void setColor(const std::string &color);

    bool operator==(const Car &rhs) const;
    bool operator!=(const Car &rhs) const;

    std::string toString();
};


#endif //UNTITLED_DOMAIN_H
