//
// Created by theo on 25.04.2023.
//

#ifndef WEEK_8___TEST_PREP_REPOSITORY_H
#define WEEK_8___TEST_PREP_REPOSITORY_H
#include <vector>
#include "Domain.h"


class Repository {
    private:
        std::vector<Bill> bills;
    public:
        Repository();
        ~Repository();

        bool addBill(Bill bill);
        bool removeBill(const Bill& bill);
        bool updateBill(const Bill& bill, const Bill& newBill);

        std::vector<Bill> getAllBills();
};


#endif //WEEK_8___TEST_PREP_REPOSITORY_H
