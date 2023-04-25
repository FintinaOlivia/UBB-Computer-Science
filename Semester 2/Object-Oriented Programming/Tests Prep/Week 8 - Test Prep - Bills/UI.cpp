//
// Created by theo on 25.04.2023.
//

#include "UI.h"
#include <iostream>

UI::UI(const Controller &controller) {
    this->controller = controller;
}

UI::~UI() = default;

void UI::printMenu() {
    std::cout << "1. Add a bill" << std::endl;
    std::cout << "2. Remove a bill" << std::endl;
    std::cout << "3. Update a bill" << std::endl;
    std::cout << "4. Display all bills" << std::endl;
    std::cout << "5. Display paid bills" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

void UI::addBill() {
    std::string companyName;
    std::string serialNumber;
    double sum;
    bool isPaid;

    std::cout << "Company name: ";
    std::cin >> companyName;
    std::cout << "Serial number: ";
    std::cin >> serialNumber;
    std::cout << "Sum: ";
    std::cin >> sum;
    std::cout << "Is paid? (0/1): ";
    std::cin >> isPaid;

    Bill bill(companyName, serialNumber, sum, isPaid);
    if(this->controller.addBill(bill))
        std::cout << "Bill added successfully!" << std::endl;
    else
        std::cout << "Bill already exists!" << std::endl;
}

void UI::removeBill() {
    std::string companyName;
    std::string serialNumber;
    double sum;
    bool isPaid;

    std::cout << "Company name: ";
    std::cin >> companyName;
    std::cout << "Serial number: ";
    std::cin >> serialNumber;
    std::cout << "Sum: ";
    std::cin >> sum;
    std::cout << "Is paid? (0/1): ";
    std::cin >> isPaid;

    Bill bill(companyName, serialNumber, sum, isPaid);
    if(this->controller.removeBill(bill))
        std::cout << "Bill removed successfully!" << std::endl;
    else
        std::cout << "Bill not found!" << std::endl;
}

void UI::updateBill() {
    std::string companyName;
    std::string serialNumber;
    double sum;
    bool isPaid;

    std::cout << "Company name: ";
    std::cin >> companyName;
    std::cout << "Serial number: ";
    std::cin >> serialNumber;
    std::cout << "Sum: ";
    std::cin >> sum;
    std::cout << "Is paid? (0/1): ";
    std::cin >> isPaid;

    Bill bill(companyName, serialNumber, sum, isPaid);

    std::cout << "New company name: ";
    std::cin >> companyName;
    std::cout << "New serial number: ";
    std::cin >> serialNumber;
    std::cout << "New sum: ";
    std::cin >> sum;
    std::cout << "New is paid? (0/1): ";
    std::cin >> isPaid;

    Bill newBill(companyName, serialNumber, sum, isPaid);

    if(this->controller.updateBill(bill, newBill))
        std::cout << "Bill updated successfully!" << std::endl;
    else
        std::cout << "Bill not found!" << std::endl;
}

std::vector<Bill> sortByCompanyName(std::vector<Bill> bills) {
    for(int i = 0; i < bills.size() - 1; i++)
        for(int j = i + 1; j < bills.size(); j++)
            if(bills[i].getCompanyName() > bills[j].getCompanyName())
                std::swap(bills[i], bills[j]);
    return bills;
}

void UI::displayBillsSortedByCompanyName() {
    std::vector<Bill> bills = this->controller.getAllBills();
    std::vector<Bill> sortedBills = sortByCompanyName(bills);
for(auto bill : sortedBills)
        std::cout << bill.toString() << std::endl;
}

void UI::displayPaidBills() {
    std::vector<Bill> bills = this->controller.getAllBills();
    for (auto bill: bills)
        if (bill.isBillPaid()) {
            std::cout << bill.toString() << std::endl;
        }
    std::cout << "Total sum: " << this->controller.getTotalSumOfBills() << std::endl;
}

void UI::startApplication() {
    std::cout << "Welcome to the bill management application!" << std::endl;
    while(true) {
        this->printMenu();
        int option;
        std::cout << "Option: ";
        std::cin >> option;
        if(option == 1)
            this->addBill();
        else if(option == 2)
            this->removeBill();
        else if(option == 3)
            this->updateBill();
        else if(option == 4)
            this->displayBillsSortedByCompanyName();
        else if(option == 5)
            this->displayPaidBills();
        else if(option == 6)
            break;
        else
            std::cout << "Invalid option!" << std::endl;
        std::cout << std::endl;
    }

}




