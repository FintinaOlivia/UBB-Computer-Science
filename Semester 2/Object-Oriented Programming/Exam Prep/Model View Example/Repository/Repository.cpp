//
// Created by Th on 15/06/2023.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "Repository.h"

Repository::Repository(const std::string &filename) {
    this->fileName = filename;
    this->readFromFile();
}

void Repository::add(const Student &student) {
    this->students.push_back(student);
    this->writeToFile();
}

void Repository::readFromFile() {
    std::ifstream file(this->fileName);
    Student student;
    while (file >> student) {
        this->students.push_back(student);
    }
    file.close();
}

void Repository::writeToFile() {
    std::ofstream file(this->fileName);
    for (auto student : this->students) {
        file << student;
    }
    file.close();
}

void Repository::remove(const Student &student) {
    for(auto it = this->students.begin(); it != this->students.end(); ++it) {
        if (*it == student) {
            this->students.erase(it);
            break;
        }
    }

}

void sort(std::vector<std::string> vectorToSort){
    for(auto elem : vectorToSort){
        std::sort(elem.begin(), elem.end());
    }
}