//
// Created by theo on 25.04.2023.
//

#ifndef WEEK_8___TEST_PREP_CONTROLLER_H
#define WEEK_8___TEST_PREP_CONTROLLER_H
#include "Repository.h"

class Controller {
    private:
        Repository repository;

    public:
        explicit Controller(const Repository& repository);
        Controller();
        ~Controller();

        bool addBill(const Bill& bill);
        bool removeBill(const Bill& bill);
        bool updateBill(const Bill& bill, const Bill& newBill);

        std::vector<Bill> getAllBills();

        double getTotalSumOfBills();
};


#endif //WEEK_8___TEST_PREP_CONTROLLER_H
