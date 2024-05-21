//
// Created by Th on 30/05/2023.
//

#include "UserModeGUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "windows.h"
#include <qlabel.h>
#include <QMessageBox>

UserModeGUI::UserModeGUI(Service &service, AbstractShoppingBasket* ASB, QWidget* parent): service{service}, ASB{ASB}, QDialog{parent} {
    this->initUserModeGUI();
    this->connectSignalsAndSlots();
}

void UserModeGUI::initUserModeGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->shoppingBasketListWidget = new QListWidget{};
    this->shoppingBasketListWidget->setFont(buttonsFont);

    this->sizeComboBox = new QComboBox{};
    this->sizeComboBox->setFont(buttonsFont);

    this->sizeComboBox->addItem("All sizes");
    this->sizeComboBox->addItem("XXS");
    this->sizeComboBox->addItem("XS");
    this->sizeComboBox->addItem("S");
    this->sizeComboBox->addItem("M");
    this->sizeComboBox->addItem("L");
    this->sizeComboBox->addItem("XL");
    this->sizeComboBox->addItem("XXL");

    this->displayProductsButton = new QPushButton{"Display Products"};
    this->displayProductsButton->setFont(buttonsFont);

    this->displayShoppingBasketButton = new QPushButton{"Display Shopping Basket"};
    this->displayShoppingBasketButton->setFont(buttonsFont);

    this->openApplicationButton = new QPushButton{"Open Application"};
    this->openApplicationButton->setFont(buttonsFont);

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *size = new QLabel();
    size->setText("Size");
    size->setFont(buttonsFont);

    QLabel *coatsText = new QLabel();
    coatsText->setText("Shopping Basket");
    QFont coatsFont("Consolas", 15, true);
    coatsText->setFont(coatsFont);

    QVBoxLayout* userLayout = new QVBoxLayout( this );
    userLayout->addWidget(coatsText);
    userLayout->addWidget(this->shoppingBasketListWidget);

    QFormLayout* coatDetails = new QFormLayout();
    coatDetails->addRow(size, this->sizeComboBox);
    userLayout->addLayout(coatDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->displayProductsButton, 0, 0);
    buttonsLayout->addWidget(this->displayShoppingBasketButton, 1, 0);
    buttonsLayout->addWidget(this->openApplicationButton, 2, 0);

    userLayout->addLayout(buttonsLayout);

    QWidget *userDisplayWindow = new QWidget();
    userDisplayWindow->setLayout(userLayout);
    userDisplayWindow->show();
}

void UserModeGUI::connectSignalsAndSlots() {
    QObject::connect(this->displayProductsButton, &QPushButton::clicked, this, &UserModeGUI::displayProducts);
    QObject::connect(this->displayShoppingBasketButton, &QPushButton::clicked, this, &UserModeGUI::populateShoppingBag);
    QObject::connect(this->openApplicationButton, &QPushButton::clicked, this, &UserModeGUI::openApplication);
}

void UserModeGUI::connectSignalsAndSlotsDisplayFunction() {
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &UserModeGUI::nextProduct);
    QObject::connect(this->buyButton, &QPushButton::clicked, this, &UserModeGUI::buyProduct);
}

UserModeGUI::~UserModeGUI() {

}

int UserModeGUI::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserModeGUI::displayProducts() {
    if(this->service.GetRepository().size() == 0) {
        QMessageBox::critical(this, "Error", "There are no products on the stock!");
        return;
    }
    else {
        this->size = this->sizeComboBox->currentText().toStdString();
        this->initDisplayProducts();
        this->displayUserProducts();
    }
}

void UserModeGUI::initDisplayProducts() {
    QFont buttonsFont("Consolas", 13, true);

    this->coatsListWidget = new QListWidget{};
    this->coatsListWidget->setFont(buttonsFont);

    this->nextButton = new QPushButton{"Next"};
    this->nextButton->setFont(buttonsFont);

    this->buyButton = new QPushButton{"Buy"};
    this->buyButton->setFont(buttonsFont);


    QLabel *coatsText = new QLabel();
    coatsText->setText("Products");
    QFont coatsFont("Consolas", 15, true);
    coatsText->setFont(coatsFont);

    QVBoxLayout* displayLayout = new QVBoxLayout();
    displayLayout->addWidget(coatsText);
    displayLayout->addWidget(this->coatsListWidget);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->nextButton, 0, 0);
    buttonsLayout->addWidget(this->buyButton, 0, 1);
//    buttonsLayout->addWidget(this->payButton, 0, 2);

    displayLayout->addLayout(buttonsLayout);
    QWidget *mainDisplayWindow = new QWidget();
    mainDisplayWindow->setLayout(displayLayout);
    mainDisplayWindow->show();
}

void UserModeGUI::populateDisplayProducts(int position, std::vector<Coat> coats) {
    this->coatsListWidget->clear();
    Coat c = coats[position];
//    this->position = position;
    this->coatsListWidget->addItem(QString::fromStdString(c.GetSize() + " - " + c.GetColor() + " - " + std::to_string(c.GetPrice()) + " - " + std::to_string(c.GetQuantity())
                                                          + " - " + c.GetPhotograph()));
    ShellExecute(nullptr, reinterpret_cast<LPCWSTR>("open"),
                 reinterpret_cast<LPCWSTR>(coats[position].GetPhotograph().c_str()), NULL, NULL, SW_SHOWNORMAL);
}

void UserModeGUI::populateShoppingBag() {
    this->shoppingBasketListWidget->clear();
    std::vector<Coat> Coats = this->service.GetUserRepository();
    for (Coat &c: Coats) {
        this->shoppingBasketListWidget->addItem(QString::fromStdString(c.GetSize() + " - " + c.GetColor() + " - " + std::to_string(c.GetPrice()) + " - " + std::to_string(c.GetQuantity())
                                                                       + " - " + c.GetPhotograph()));

    }
}

void UserModeGUI::clearPopulatedList() {
    this->coatsListWidget->clear();
}

void UserModeGUI::nextProduct() {
    std::vector<Coat> coats = this->service.GetFilteredRepository(this->size);
    if(coats.empty()) {
        QMessageBox::critical(this, "Error", "There are no products on the stock!");
        return;
    }
    if(this->position == coats.size()-1)
        this->position = 0;
    else
        this->position += 1;
    this->populateDisplayProducts(this->position, coats);

}

void UserModeGUI::buyProduct() {
    std::vector<Coat> coats = this->service.GetFilteredRepository(this->size);
    if(coats.empty()) {
        QMessageBox::critical(this, "Error", "There are no products on the stock!");
        return;
    }
    int pos = this->position;
    int i = this->getSelectedIndex();
    if(i == -1){
        QMessageBox::critical(this, "Error", "Please select the item!");
        return;
    }
    else {
        if(coats[pos].GetQuantity() == 1 && coats.size() == 1)
        {
            QMessageBox::information(this, "Information", "Congratulations! You spent all your money and bought everything :) !");
            this->clearPopulatedList();

        }
        else if (coats[pos].GetQuantity() == 1) {
            this->populateDisplayProducts(this->position++, coats);
        }
        this->service.UpdateQuantityService(coats[pos].GetSize(), coats[pos].GetColor(), coats[pos].GetPhotograph(),
                                            coats[pos].GetQuantity() - 1);

        Coat oldCoat(coats[pos].GetSize(), coats[pos].GetColor(), coats[pos].GetPrice(), coats[pos].GetQuantity() - 1,
                     coats[pos].GetPhotograph());
        Coat addedCoat(coats[pos].GetSize(), coats[pos].GetColor(), coats[pos].GetPrice(), 1, coats[pos].GetPhotograph());

        this->service.AddUserService(oldCoat, addedCoat);
    }
}

void UserModeGUI::displayUserProducts() {
    this->position = 0;
    std::vector<Coat> coats = this->service.GetFilteredRepository(this->size);
    if(coats.empty())
    {
        QMessageBox::critical(this, "Error", "There are no products on the stock!");
        return;
    }
    this->populateDisplayProducts(0, coats);
    this->connectSignalsAndSlotsDisplayFunction();
}

void UserModeGUI::openApplication() {
    this->ASB->set_data(this->service.GetUserRepository());
    this->ASB->write();
    this->ASB->open();

}