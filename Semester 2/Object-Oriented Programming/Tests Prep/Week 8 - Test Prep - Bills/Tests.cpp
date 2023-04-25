//
// Created by theo on 25.04.2023.
//

#include "Tests.h"
#include <cassert>
#include <iostream>

void Tests::testTotalSumOfBills() {
    Repository repository;
    Controller controller(repository);
    Bill billToAdd = Bill("Google", "lala", 100, false);
    controller.addBill(billToAdd);
    //assert(controller.getTotalSumOfBills() == 100);
    Bill billToAdd2 = Bill("Apple", "fifi", 300, true);
    controller.addBill(billToAdd2);
    //assert(controller.getTotalSumOfBills() == 400);
    Bill billToAdd3 = Bill("Microsoft", "fifi", 200, false);
    controller.addBill(billToAdd3);
    //assert(controller.getTotalSumOfBills() == 600);
    assert(controller.getTotalSumOfBills() == 300);

    std::cout << "Test Total Sum of Paid Bills passed!\n";
}

void Tests::testAddBill() {
    Repository repository;
    Controller controller(repository);
    Bill billToAdd = Bill("Google", "lala", 100, false);
    assert(controller.addBill(billToAdd));
    assert(!controller.addBill(billToAdd));
    Bill billToAdd2 = Bill("Apple", "fifi", 300, true);
    assert(controller.addBill(billToAdd2));
    Bill billToAdd3 = Bill("Microsoft", "fifi", 200, false);
    assert(controller.addBill(billToAdd3));
    assert(!controller.addBill(billToAdd));
    assert(!controller.addBill(billToAdd2));
    assert(!controller.addBill(billToAdd3));

    std::cout << "Test Add Bill passed!\n";
}



