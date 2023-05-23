//
// Created by Th on 20/05/2023.
//

#include <algorithm>
#include "Service.h"

Service::Service(Repository &repository) : repository(repository) {}

Service::~Service() {}

std::vector<Bill> Service::getAll() {
    return this->repository.getAll();
}



std::vector<Bill> Service::sortByName() {
    std::vector<Bill> bills = this->repository.getAll();
    std::sort(bills.begin(), bills.end(), [](Bill b1, Bill b2) {
        return b1.getCompanyName() < b2.getCompanyName();
    });
    return bills;
}

std::vector<Bill> Service::getByName(std::string name) {
    std::vector<Bill> bills = this->repository.getAll();
    std::vector<Bill> filtered;
    std::copy_if(bills.begin(), bills.end(), std::back_inserter(filtered), [name](Bill b) {
        return b.getCompanyName() == name;
    });
    return filtered;
}

