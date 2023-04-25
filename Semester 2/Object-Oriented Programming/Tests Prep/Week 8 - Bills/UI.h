//
// Created by theo on 25.04.2023.
//

#ifndef WEEK_8___TEST_PREP_UI_H
#define WEEK_8___TEST_PREP_UI_H
#include "Controller.h"

class UI {
    private:
        Controller controller;
    public:
        explicit UI(const Controller& controller);
        ~UI();
        void startApplication();
        static void printMenu();

        void addBill();
        void removeBill();
        void updateBill();
        void displayBillsSortedByCompanyName();
        void displayPaidBills();
};


#endif //WEEK_8___TEST_PREP_UI_H
