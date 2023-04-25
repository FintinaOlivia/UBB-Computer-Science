//
// Created by theo on 25.04.2023.
//

#include "Repository.h"

Repository::Repository() {
    this->bills = std::vector<Bill>();
}

Repository::~Repository() {
    this->bills.clear();
}

bool Repository::addBill(Bill bill) {
    /*
     * Check if the bill already exists in the repository
     * If it does, return false
     * If it doesn't, add the bill to the repository and return true
     */

    for (auto & i : this->bills) {
        if (i.getSerialNumber() == bill.getSerialNumber() && \
        i.getCompanyName() == bill.getCompanyName()) {
            return false;
        }
    }
    this->bills.push_back(bill);
    return true;
}

bool Repository::removeBill(const Bill& bill) {
    for (int i = 0; i < this->bills.size(); i++) {
        if (this->bills[i].equals(bill)) {
            this->bills.erase(this->bills.begin() + i);
            return true;
        }
    }
    return false;
}

bool Repository::updateBill(const Bill& bill, const Bill& newBill) {
    for (auto & i : this->bills) {
        if (i.equals(bill)) {
            i = newBill;
            return true;
        }
    }
    return false;
}

std::vector<Bill> Repository::getAllBills() {
    return this->bills;
}


