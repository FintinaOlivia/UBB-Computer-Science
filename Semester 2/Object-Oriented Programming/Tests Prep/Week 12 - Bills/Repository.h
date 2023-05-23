//
// Created by Th on 20/05/2023.
//

#ifndef W12_TEST_ATTEMPT_BILLS_REPOSITORY_H
#define W12_TEST_ATTEMPT_BILLS_REPOSITORY_H


#include <vector>
#include "Domain/Bill.h"

class Repository {
private:
    std::vector<Bill> elements{};
    void LoadData();
public:
    Repository();
    ~Repository();
    std::vector<Bill> getAll();

};


#endif //W12_TEST_ATTEMPT_BILLS_REPOSITORY_H
