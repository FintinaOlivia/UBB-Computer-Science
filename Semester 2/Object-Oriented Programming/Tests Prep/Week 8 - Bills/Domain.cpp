//
// Created by theo on 25.04.2023.
//

#include "Domain.h"

#include <utility>

Bill::Bill() {
    this->companyName = "";
    this->serialNumber = "";
    this->sum = 0;
    this->isPaid = false;
}

Bill::Bill(std::string companyName, std::string serialNumber, double sum, bool isPaid) {
    this->companyName = std::move(companyName);
    this->serialNumber = std::move(serialNumber);
    this->sum = sum;
    this->isPaid = isPaid;
}

Bill::Bill(const Bill &bill) {
    this->companyName = bill.companyName;
    this->serialNumber = bill.serialNumber;
    this->sum = bill.sum;
    this->isPaid = bill.isPaid;
}

Bill::~Bill() = default;

//Getters
std::string Bill::getCompanyName() {
    return this->companyName;
}

std::string Bill::getSerialNumber() {
    return this->serialNumber;
}

double Bill::getSum() {
    return this->sum;
}

bool Bill::isBillPaid() {
    return this->isPaid;
}

//Setters

void Bill::setCompanyName(std::string companyName) {
    this->companyName = std::move(companyName);
}

void Bill::setSum(double sum) {
    this->sum = sum;
}

void Bill::setSerialNumber(std::string serialNumber) {
    this->serialNumber = std::move(serialNumber);
}

void Bill::setIsPaid(bool isPaid) {
    this->isPaid = isPaid;
}

//__str__()
std::string Bill::toString() {
    return "Company name: " + this->companyName \
    + ", serial number: " + this->serialNumber \
    + ", sum: " + std::to_string(this->sum) \
    + ", is paid: " + std::to_string(this->isPaid);
}

//__eq__()
bool Bill::equals(Bill bill) {
    return this->companyName == bill.companyName
            && this->serialNumber == bill.serialNumber
            && this->sum == bill.sum
            && this->isPaid == bill.isPaid;
}

