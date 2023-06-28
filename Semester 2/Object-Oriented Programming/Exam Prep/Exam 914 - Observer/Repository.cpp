//
// Created by Th on 14/06/2023.
//

#include "Repository.h"
#include <fstream>

Repository::Repository() {
    this->loadDepartments();
    this->loadVolunteers();
    sortByName(this->volunteers);
}

void Repository::loadDepartments() {
    std::ifstream inFile(R"(C:\Users\Th\CLionProjects\ExamPrep914\departments.txt)");
    Department CurrentElement;
    this->departments.clear();
    while (inFile >> CurrentElement)
    {
        this->departments.push_back(CurrentElement);
    }
    inFile.close();
}

void Repository::loadVolunteers() {
    std::ifstream inFile(R"(C:\Users\Th\CLionProjects\ExamPrep914\volunteers.txt)");
    Volunteer CurrentElement;
    this->volunteers.clear();
    while (inFile >> CurrentElement)
    {
        this->volunteers.push_back(CurrentElement);
    }
    inFile.close();
}

void Repository::notify() {
    for (auto observer:observers){
        observer->update();
    }
}

std::vector<Department> Repository::getDepartments() {
    return this->departments;
}

std::vector<Volunteer> Repository::getVolunteers() {
    return this->volunteers;
}

void Repository::sortByName(std::vector<Volunteer> &volunteers) {
    for (int i = 0; i < volunteers.size() - 1; i++) {
        for (int j = i + 1; j < volunteers.size(); j++) {
            if (volunteers[i].getName() > volunteers[j].getName()) {
                std::swap(volunteers[i], volunteers[j]);
            }
        }
    }
}

void Repository::addVolunteer(const Volunteer &volunteer) {
    this->volunteers.push_back(volunteer);
    this->notify();
    this->saveToFile();
}

void Repository::registerObserver(Observer* observer) {
    this->observers.push_back(observer);
}

void Repository::deleteVolunteer(const Volunteer &volunteer) {
    for (int i = 0; i < this->volunteers.size(); i++) {
        if (this->volunteers[i].getName() == volunteer.getName()) {
            this->volunteers.erase(this->volunteers.begin() + i);
            this->notify();
            return;
        }
    }

}

void Repository::saveToFile() {
    std::ofstream outFile(R"(C:\Users\Th\CLionProjects\ExamPrep914\volunteers.txt)");
    for (auto volunteer:this->volunteers) {
        std::string line = volunteer.toString();
        outFile << line << std::endl;
    }
}
