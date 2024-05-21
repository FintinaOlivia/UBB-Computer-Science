//
// Created by Th on 30/05/2023.
//

#include "../Service/service.h"
#include "../Validation/validation.h"
#include <QVBoxLayout>
#include "../AdminModeGUI/AdminModeGUI.h"
#include "../UserModeGUI/UserModeGUI.h"
#include "../AbstractShoppingBasket/AbstractShoppingBasket.h"

#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QMainWindow>

class GUI: public QMainWindow
{
Q_OBJECT
private:
    std::string type = "empty";
    Service& service;
    AbstractShoppingBasket* ASB;
    void initGUI();
    ///Graphical elements
    QComboBox *filetypeComboBox;
    QPushButton* adminModeButton, * userModeButton, *saveButton;

public:
    GUI(Service& service, QWidget *parent = 0);
    ~GUI();
    void connectSignalsAndSlots();
    void startUserModeGUI();
    void startAdminModeGUI();
    void saveFileType();
    //void createChart();

};
