//
// Created by Th on 30/05/2023.
//

#include <cstring>
#include "domain.h"
#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <sstream>

Coat::Coat() {
}

Coat::Coat(std::string size, std::string color,
           int price, int quantity,
           std::string photograph):
        size{std::move(size)},
        color{std::move(color)},
        price{price},
        quantity{quantity},
        photograph{std::move(photograph)}{
}


void Coat::SetQuantity(int quantity) {
    this->quantity = quantity;
}

void Coat::SetPrice(int price) {
    this->price = price;
}

const std::string& Coat::GetSize() const{
    return this->size;
}

const std::string& Coat::GetColor() const{
    return this->color;
}

const int& Coat::GetPrice() const{
    return this->price;
}

int Coat::GetQuantity() const{
    return this->quantity;
}

const std::string& Coat::GetPhotograph() const{
    return this->photograph;
}

Coat &Coat::operator=(const Coat &coat) {
    this->size = coat.size;
    this->color = coat.color;
    this->price = coat.price;
    this->quantity = coat.quantity;
    this->photograph = coat.photograph;
    return *this;
}

std::vector<std::string> Coat::tokenize(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::ostream &operator<<(std::ostream &output, const Coat &coat) {
    output << coat.size << "," << coat.color << "," << coat.price << "," << coat.quantity << "," << coat.photograph;
    return output;
}

std::istream &operator>>(std::istream &input, Coat &coat) {
    std::string line;
    getline(input, line);
    std::vector<std::string> tokens = Coat::tokenize(line, ',');
    if(tokens.size() != 5)
        return input;
    coat.size = tokens[0];
    coat.color = tokens[1];
    coat.price = stoi(tokens[2]);
    coat.quantity = stoi(tokens[3]);
    coat.photograph = tokens[4];
    return input;
}