//
// Created by Th on 14/06/2023.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "Volunteer.h"



const std::string &Volunteer::getName() const {
    return name;
}

const std::string &Volunteer::getEmail() const {
    return email;
}

const std::string &Volunteer::getInterests() const {
    std::string interestsString;
    for (const auto &interest : interests) {
        interestsString += interest + " ";
    }
    return interestsString;
}


std::istream &operator>>(std::istream &is, Volunteer &volunteer) {
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, ';')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 4) {
        return is;
    }

    volunteer.name = tokens[0];
    volunteer.email = tokens[1];
    volunteer.departament = tokens[3];

    std::stringstream ss2(tokens[2]);
    std::string interest;
    while (getline(ss2, interest, ',')) {
        volunteer.interests.push_back(interest);
    }


    return is;
}

Volunteer::Volunteer(const std::string &name, const std::string &email, const std::vector<std::string> &interests,
                     const std::string &departament) {
    this->name = name;
    this->email = email;
    this->interests = interests;
    this->departament = departament;
}

Volunteer::Volunteer() {
    this->name = "";
    this->email = "";
    this->departament = "";
    this->interests = std::vector<std::string>();

}

std::string Volunteer::getDepartment() {
    return this->departament;
}

void Volunteer::setDepartment(const std::string &basicString) {
    this->departament = basicString;
}

std::string Volunteer::toString() {
    std::string interestsString;
    for (const auto &interest : interests) {
        interestsString += interest + ",";
    }
    return this->name + ";" + this->email + ";" + interestsString + ";" + this->departament;
}


