//
// Created by Th on 30/05/2023.
//

#pragma once
#include <QVBoxLayout>
#include <qwidget.h>
#include <qlistwidget.h>
#include "../AbstractShoppingBasket/AbstractShoppingBasket.h"
#include "../Service/service.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QDialog>

class UserModeGUI: public QDialog {

private:
    std::string size;
    int position;
    AbstractShoppingBasket* ASB;
    Service& service;
    QListWidget* coatsListWidget;
    QListWidget* shoppingBasketListWidget;
    QComboBox *sizeComboBox;
    QPushButton* displayProductsButton, * openApplicationButton, * displayShoppingBasketButton;
    QPushButton* nextButton, * buyButton;

public:
    UserModeGUI(Service& service, AbstractShoppingBasket* ASB, QWidget* parent = nullptr);
    ~UserModeGUI();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void initUserModeGUI();

    void connectSignalsAndSlotsDisplayFunction();

    void populateShoppingBag();

    void openApplication();

    void populateDisplayProducts(int position, std::vector<Coat> coats);
    void displayUserProducts();
    void nextProduct();
    void buyProduct();
    void initDisplayProducts();
    void displayProducts();
    void clearPopulatedList();

};

