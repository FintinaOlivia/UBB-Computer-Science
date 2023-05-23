//
// Created by Th on 23/05/2023.
//

#ifndef T3_CARS_GUI_H
#define T3_CARS_GUI_H


#include "../Controller/Controller.h"
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>


class GUI: public QWidget{
private:
    Controller& controller;
    void initGUI();

    void connectSignalsAndSlots();
    void displayAllWithColouredFonts();
    void showCars();

    QListWidget* carsListWidget;
    QLineEdit* manufacturerLineEdit;
    QPushButton* showCarsButton;

public:
    explicit GUI(Controller &controller);
    ~GUI() override;

    void populateList(std::vector<Car> cars);
};


#endif //T3_CARS_GUI_H
