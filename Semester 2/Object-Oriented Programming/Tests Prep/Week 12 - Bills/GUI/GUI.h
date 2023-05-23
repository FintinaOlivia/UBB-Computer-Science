//
// Created by Th on 20/05/2023.
//

#ifndef W12_TEST_ATTEMPT_BILLS_GUI_H
#define W12_TEST_ATTEMPT_BILLS_GUI_H


#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include "../Service/Service.h"

class GUI : public QWidget {
private:
    Service& service;
    void initGUI();
    void connectSignalsAndSlots();

    void displayAll();
    void sortByCompanyName();
    void displayUnpaidBills();

    QListWidget* billsListWidget;
    QListWidget* unpaidBillsListWidget;
    QPushButton* sortButton;
    QLineEdit* nameLineEdit;
    QPushButton* calculateSumButton;
public:
    explicit GUI(Service &service);
    ~GUI() override;
    void populateList(std::vector<Bill> bills);
};


#endif //W12_TEST_ATTEMPT_BILLS_GUI_H
