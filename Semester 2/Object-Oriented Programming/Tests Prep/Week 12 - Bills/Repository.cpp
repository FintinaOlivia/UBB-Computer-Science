//
// Created by Th on 20/05/2023.
//

#include <fstream>
#include "Repository.h"
#include "Domain/Bill.h"

Repository::Repository() {
    this->LoadData();
}

Repository::~Repository() = default;

std::vector<Bill> Repository::getAll() {
    return this->elements;
}

void Repository::LoadData() {
    std::ifstream inFile(R"(C:\Users\Th\CLionProjects\W12-Test-Attempt-Bills\input.txt)");
    Bill CurrentElement;
    this->elements.clear();
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
    inFile.close();

}


