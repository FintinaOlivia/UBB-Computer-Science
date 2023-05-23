//
// Created by Th on 20/05/2023.
//

#include <QVBoxLayout>
#include <iostream>
#include "GUI.h"

GUI::GUI(Service &service) : service(service) {
    this->initGUI();
    this->connectSignalsAndSlots();
    this->displayAll();
}

GUI::~GUI() = default;

void GUI::initGUI() {
    this->billsListWidget = new QListWidget{};
    this->sortButton = new QPushButton{"Sort"};
    this->nameLineEdit = new QLineEdit{"Company name"};
    this->nameLineEdit->setFocus();
    this->calculateSumButton = new QPushButton{"Calculate sum"};
    this->unpaidBillsListWidget = new QListWidget{};

    auto* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(this->billsListWidget);
    mainLayout->addWidget(this->sortButton);
    mainLayout->addWidget(this->nameLineEdit);
    mainLayout->addWidget(this->calculateSumButton);
    mainLayout->addWidget(this->unpaidBillsListWidget);

    this->setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->sortButton,
                     &QPushButton::clicked,
                     this,
                     &GUI::sortByCompanyName);

    QObject::connect(this->calculateSumButton,
                     &QPushButton::clicked,
                     this,
                     &GUI::displayUnpaidBills);
}

void GUI::displayAll() {
    this->billsListWidget->clear();
    std::vector<Bill> bills = this->service.getAll();
    for (auto &bill : bills) {
        QString itemInList = QString::fromStdString(bill.getCompanyName() + " - " + std::to_string(bill.getSum()));
        this->billsListWidget->addItem(itemInList);
    }
}

void GUI::sortByCompanyName() {
    this->billsListWidget->clear();
    std::vector<Bill> bills = this->service.sortByName();
    for (auto &bill : bills) {
        QString itemInList = QString::fromStdString(bill.getCompanyName() + " - " + std::to_string(bill.getSum()));
        this->billsListWidget->addItem(itemInList);
    }
}

void GUI::displayUnpaidBills() {
    this->billsListWidget->clear();

    auto *window = new QWidget;
    window->setWindowTitle("Unpaid bills");
    window->setFixedSize(200, 100);
    auto *layout = new QVBoxLayout;
    window->setLayout(layout);

    std::string companyName = this->nameLineEdit->text().toStdString();
    std::vector<Bill> bills = this->service.getByName(companyName);
    double sum = 0;
    for (auto &bill : bills) {
        if(!bill.getIsPaid()) {
            QString itemInList = QString::fromStdString(bill.getCompanyName() + " - " + std::to_string(bill.getSum()));
            sum += bill.getSum();
            this->billsListWidget->addItem(itemInList);
        }
    }
    QString itemInList = QString::fromStdString("Sum: " + std::to_string(sum));
    this->unpaidBillsListWidget->addItem(itemInList);
}

void GUI::populateList(std::vector<Bill> bills) {
    this->billsListWidget->clear();
    for (auto &bill : bills) {
        QString itemInList = QString::fromStdString(bill.getCompanyName() + " - " + std::to_string(bill.getSum()));
        this->billsListWidget->addItem(itemInList);
    }

}

