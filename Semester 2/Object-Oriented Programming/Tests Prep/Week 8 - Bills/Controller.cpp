//
// Created by theo on 25.04.2023.
//

#include "Controller.h"

[[maybe_unused]] Controller::Controller(const Repository& repository) {
    this->repository = repository;
}

Controller::Controller() {
    this->repository = Repository();
}

Controller::~Controller() = default;

bool Controller::addBill(const Bill& bill) {
    return this->repository.addBill(bill);
}

bool Controller::removeBill(const Bill& bill) {
    return this->repository.removeBill(bill);
}

bool Controller::updateBill(const Bill& bill, const Bill& newBill) {
    return this->repository.updateBill(bill, newBill);
}

std::vector<Bill> Controller::getAllBills() {
    return this->repository.getAllBills();
}

double Controller::getTotalSumOfBills() {
    /*
     * Function gets all bills from repository and sums up
     * the sum of each bill
     */
    double sum = 0;
    for (auto bill : this->repository.getAllBills()){
        if(bill.isBillPaid())
            sum += bill.getSum();
    }
    return sum;
}


