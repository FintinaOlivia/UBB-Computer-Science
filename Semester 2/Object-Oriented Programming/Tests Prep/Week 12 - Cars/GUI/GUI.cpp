//
// Created by Th on 23/05/2023.
//

#include <QVBoxLayout>
#include <QFont>
#include <QPalette>
#include <QMessageBox>
#include "GUI.h"

GUI::GUI(Controller &controller) : controller(controller) {
    this->initGUI();
    this->connectSignalsAndSlots();
}

GUI::~GUI() {
    delete this->carsListWidget;
    delete this->manufacturerLineEdit;
    delete this->showCarsButton;
}

void GUI::initGUI() {
    this->carsListWidget = new QListWidget{};
    this->manufacturerLineEdit = new QLineEdit{};
    this->showCarsButton = new QPushButton{"Show cars"};

    this->displayAllWithColouredFonts();

    auto* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(this->carsListWidget);
    mainLayout->addWidget(this->manufacturerLineEdit);
    mainLayout->addWidget(this->showCarsButton);

    this->setLayout(mainLayout);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->showCarsButton,
                     &QPushButton::clicked,
                     this,
                     &GUI::showCars);
    QObject::connect(this->manufacturerLineEdit,
                     &QLineEdit::textChanged,
                     this,
                     &GUI::displayAllWithColouredFonts);

}

void GUI::displayAllWithColouredFonts() {
    this->carsListWidget->clear();
    std::vector<Car> cars = this->controller.getAll();
    for (auto &car : cars) {
        QString itemInList = QString::fromStdString(car.toString());
        QFont font{ "Courier", 10, 10 };
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        //This displays the colour of the car in the said colour using QColor

        auto* item = new QListWidgetItem{itemInList, this->carsListWidget};
        item->setForeground(QColor{car.getColour().c_str()});

        this->carsListWidget->addItem(item);
        this->carsListWidget->item(this->carsListWidget->count() - 1)->setFont(font);
    }
}

void GUI::showCars() {
    std::string manufacturer = this->manufacturerLineEdit->text().toStdString();
    std::vector<Car> cars = this->controller.filterByManufacturer(manufacturer);
    int numberOfCars = this->controller.getNumberOfCarsByManufacturer(manufacturer);
    if (numberOfCars == 0) {
        QMessageBox::critical(this, "Error", "There are no cars with the given manufacturer!");
        return;
    }else{
        QMessageBox::information(this, "Success", "There is a grand number of " + QString::number(numberOfCars) + " car(s) with the given manufacturer!");
    }
    //this->populateList(cars);
    auto* newWidget = new QListWidget{};
    newWidget->clear();
    for (auto &car : cars) {
        QString itemInList = QString::fromStdString(car.toString());
        newWidget->addItem(itemInList);
    }
    newWidget->show();
}

void GUI::populateList(std::vector<Car> cars) {
    this->carsListWidget->clear();
    for (auto &car : cars) {
        QString itemInList = QString::fromStdString(car.toString());
        this->carsListWidget->addItem(itemInList);
    }
}


