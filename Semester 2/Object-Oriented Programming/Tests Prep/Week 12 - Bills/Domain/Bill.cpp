//
// Created by Th on 20/05/2023.
//

#include <vector>
#include <sstream>
#include "Bill.h"

Bill::Bill() = default;

Bill::Bill(std::string companyName, std::string code, double sum, bool isPaid) {
    this->companyName = companyName;
    this->code = code;
    this->sum = sum;
    this->isPaid = isPaid;
}

Bill::~Bill() = default;

std::string Bill::getCompanyName() {
    return this->companyName;
}

std::string Bill::getCode() {
    return this->code;
}

double Bill::getSum() {
    return this->sum;
}

bool Bill::getIsPaid() {
    return this->isPaid;
}

bool Bill::operator==(const Bill &bill) {
    return this->companyName == bill.companyName && this->code == bill.code && this->sum == bill.sum &&
           this->isPaid == bill.isPaid;
}

std::istream &operator>>(std::istream &is, Bill &bill) {
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

    bill.companyName = tokens[0];
    bill.code = tokens[1];
    bill.sum = stod(tokens[2]);
    bill.isPaid = tokens[3] == "true";

    return is;
}