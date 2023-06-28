//
// Created by Th on 14/06/2023.
//

#include "Department.h"
#include <sstream>
#include <vector>


Department::Department(const std::string &name, const std::string &description) {
    this->name = name;
    this->description = description;
}

const std::string &Department::getName() const {
    return name;
}

const std::string &Department::getDescription() const {
    return description;
}

std::istream &operator>>(std::istream &is, Department &department) {
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, ';')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 2) {
        return is;
    }

    department.name = tokens[0];
    department.description = tokens[1];
    return is;
}

std::ostream &operator<<(std::ostream &os, const Department &department) {
    os << department.name << " " << department.description;
    return os;
}

Department::Department() {
    this->name = "";
    this->description = "";
}

