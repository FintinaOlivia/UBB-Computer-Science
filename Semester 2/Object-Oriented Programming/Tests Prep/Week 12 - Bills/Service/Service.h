//
// Created by Th on 20/05/2023.
//

#ifndef W12_TEST_ATTEMPT_BILLS_SERVICE_H
#define W12_TEST_ATTEMPT_BILLS_SERVICE_H


#include "../Repository.h"
#include "../Domain/Bill.h"

class Service {
private:
    Repository& repository;
public:
    explicit Service(Repository& repository);
    ~Service();
    std::vector<Bill> getAll();
    std::vector<Bill> sortByName();
    std::vector<Bill> getByName(std::string name);
};


#endif //W12_TEST_ATTEMPT_BILLS_SERVICE_H
