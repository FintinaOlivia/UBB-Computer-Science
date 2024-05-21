//
// Created by Th on 30/05/2023.
//
#include "AdminModeGUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include <qlabel.h>
#include <QMessageBox>
#include "../Validation/validation.h"

AdminModeGUI::AdminModeGUI(Service &service, QWidget* parent): service{service}, QDialog{parent} {
    this->initAdminModeGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminModeGUI::initAdminModeGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->coatsListWidget = new QListWidget{};
    this->coatsListWidget->setFont(buttonsFont);

    this->sizeComboBox = new QComboBox{};
    this->sizeComboBox->setFont(buttonsFont);

    this->sizeComboBox->addItem("XXS");
    this->sizeComboBox->addItem("XS");
    this->sizeComboBox->addItem("S");
    this->sizeComboBox->addItem("M");
    this->sizeComboBox->addItem("L");
    this->sizeComboBox->addItem("XL");
    this->sizeComboBox->addItem("XXL");

    this->colorLineEdit = new QLineEdit{};
    this->colorLineEdit->setFont(buttonsFont);

    this->priceLineEdit = new QLineEdit{};
    this->priceLineEdit->setFont(buttonsFont);

    this->quantityLineEdit = new QLineEdit{};
    this->quantityLineEdit->setFont(buttonsFont);

    this->photographLineEdit = new QLineEdit{};
    this->photographLineEdit->setFont(buttonsFont);

    this->addButton = new QPushButton{"Add"};
    this->addButton->setFont(buttonsFont);

    this->deleteSoldOutButton = new QPushButton{"Delete SoldOut"};
    this->deleteSoldOutButton->setFont(buttonsFont);

    this->deleteButton = new QPushButton{"Delete"};
    this->deleteButton->setFont(buttonsFont);

    this->updatePriceButton = new QPushButton{"Update Price"};
    this->updatePriceButton->setFont(buttonsFont);

    this->updateQuantityButton = new QPushButton{"Update Quantity"};
    this->updateQuantityButton->setFont(buttonsFont);

    this->displayButton = new QPushButton{"Display"};
    this->displayButton->setFont(buttonsFont);

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *coatsText = new QLabel();
    coatsText->setText("The list of coats");
    QFont coatsFont("Consolas", 15, true);
    coatsText->setFont(coatsFont);

    auto *size = new QLabel();
    size->setText("Size");
    size->setFont(buttonsFont);

    auto *color = new QLabel();
    color->setText("Color");
    color->setFont(buttonsFont);

    auto *price = new QLabel();
    price->setText("Price");
    price->setFont(buttonsFont);

    auto *quantity = new QLabel();
    quantity->setText("Quantity");
    quantity->setFont(buttonsFont);

    auto *photograph = new QLabel();
    photograph->setText("Photograph");
    photograph->setFont(buttonsFont);

    auto* adminLayout = new QVBoxLayout();
    adminLayout->addWidget(coatsText);
    adminLayout->addWidget(this->coatsListWidget);

    auto* coatDetails = new QFormLayout();
    coatDetails->addRow(size, this->sizeComboBox);
    coatDetails->addRow(color, this->colorLineEdit);
    coatDetails->addRow(price, this->priceLineEdit);
    coatDetails->addRow(quantity, this->quantityLineEdit);
    coatDetails->addRow(photograph, this->photographLineEdit);

    adminLayout->addLayout(coatDetails);

    auto* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->deleteSoldOutButton, 0, 2);
    buttonsLayout->addWidget(this->updatePriceButton, 1, 0);
    buttonsLayout->addWidget(this->updateQuantityButton, 1, 1);
    buttonsLayout->addWidget(this->displayButton, 1, 2);

    adminLayout->addLayout(buttonsLayout);

    QWidget *adminDisplayWindow = new QWidget();
    adminDisplayWindow->setLayout(adminLayout);
    adminDisplayWindow->show();
}

void AdminModeGUI::populateList() {
    this->coatsListWidget->clear();
    std::vector<Coat> Coats = this->service.GetRepository();
    for (Coat &coat: Coats) {
        this->coatsListWidget->addItem(QString::fromStdString(coat.GetSize() + " - " + coat.GetColor() + " - " + std::to_string(coat.GetPrice()) + " - " + std::to_string(coat.GetQuantity())
                                                              + " - " + coat.GetPhotograph()));

    }
}

void AdminModeGUI::connectSignalsAndSlots() {
    QObject::connect(this->coatsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();

        if(selectedIndex < 0)
            return;

        Coat coat = this->service.GetRepository()[selectedIndex];
        this->sizeComboBox->setCurrentText(QString::fromStdString(coat.GetSize()));
        this->colorLineEdit->setText(QString::fromStdString(coat.GetColor()));
        this->priceLineEdit->setText(QString::fromStdString(std::to_string(coat.GetPrice())));
        this->quantityLineEdit->setText(QString::fromStdString(std::to_string(coat.GetQuantity())));
        this->photographLineEdit->setText(QString::fromStdString(coat.GetPhotograph()));
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminModeGUI::addCoat);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminModeGUI::deleteCoat);
    QObject::connect(this->deleteSoldOutButton, &QPushButton::clicked, this, &AdminModeGUI::deleteSoldOutCoat);
    QObject::connect(this->updatePriceButton, &QPushButton::clicked, this, &AdminModeGUI::updatePriceCoat);
    QObject::connect(this->updateQuantityButton, &QPushButton::clicked, this, &AdminModeGUI::updateQuantityCoat);
    QObject::connect(this->displayButton, &QPushButton::clicked, this, &AdminModeGUI::populateList);

}

int AdminModeGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
    {
        this->colorLineEdit->clear();
        this->priceLineEdit->clear();
        this->quantityLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdminModeGUI::addCoat()
{
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string price = this->priceLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
    std::string photograph = this->photographLineEdit->text().toStdString();

    int validate_price = Validator::validate_price_product(price);
    int validate_quantity = Validator::validate_quantity_product(quantity);


    if(!Validator::validate_color_product(color) || validate_price == -1
       || validate_quantity == -1 || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.AddService(size, color, stoi(price), stoi(quantity), photograph);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't add the product!");
            return;
        }
    }
    this->populateList();

    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);
}

void AdminModeGUI::deleteCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string photograph = this->photographLineEdit->text().toStdString();
    if(!Validator::validate_color_product(color) || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.DeleteService(size, color, photograph, 1);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);

}

void AdminModeGUI::deleteSoldOutCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string photograph = this->photographLineEdit->text().toStdString();
    if(!Validator::validate_color_product(color) || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.DeleteService(size, color, photograph, 2);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);


}

void AdminModeGUI::updatePriceCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string photograph = this->photographLineEdit->text().toStdString();
    std::string price = this->priceLineEdit->text().toStdString();
    int validate_price = Validator::validate_price_product(price);

    if(!Validator::validate_color_product(color) || validate_price == -1
       || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.UpdatePriceService(size, color, photograph, stoi(price));
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't update the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);

}

void AdminModeGUI::updateQuantityCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string photograph = this->photographLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
    int validate_quantity = Validator::validate_quantity_product(quantity);
    if(!Validator::validate_color_product(color) || validate_quantity == -1 ||
       !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.UpdateQuantityService(size, color, photograph, stoi(quantity));;
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't update the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);
}

AdminModeGUI::~AdminModeGUI() {

}