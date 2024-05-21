

#include "GUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "../CSVShoppingBasket/CSVShoppingBasket.h"
#include "../HTMLShoppingBasket/HTMLShoppingBasket.h"
#include "qlabel.h"
#include <iostream>
#include <QMessageBox>
//#include <QtCharts>
//#include <QBarSeries>
//#include <QBarSet>



GUI::GUI(Service &service, QWidget* parent): service{service}, QMainWindow(parent)
{
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {

    QFont buttonsFont("Consolas", 13, true);

    this->saveButton = new QPushButton{"Save File Type"};
    this->saveButton->setFont(buttonsFont);

    this->adminModeButton = new QPushButton{"Admin Mode"};
    this->adminModeButton->setFont(buttonsFont);

    this->userModeButton = new QPushButton{"User Mode"};
    this->userModeButton->setFont(buttonsFont);

    this->filetypeComboBox = new QComboBox{};
    this->filetypeComboBox->setFont(buttonsFont);
    this->filetypeComboBox->addItem("CSV File");
    this->filetypeComboBox->addItem("HTML File");

    auto* mainLayout = new QVBoxLayout();

    auto *introduction = new QLabel();
    introduction->setText("WELCOME TO THE STYLISH COATS STORE!");
    introduction->setAlignment(Qt::AlignCenter);
    QFont introduction_font("Consolas", 20, true, true);
    introduction->setFont(introduction_font);

    auto *space = new QLabel();
    space->setText("");

    auto *filename = new QLabel();
    filename->setText("Choose the type of the file");
    QFont font_filename("Consolas", 15, true);
    filename->setFont(font_filename);

    mainLayout->addWidget(introduction);
    mainLayout->addWidget(space);
    mainLayout->addWidget(space);

    auto* fileDetails = new QFormLayout();
    fileDetails->addRow(filename, this->filetypeComboBox);

    mainLayout->addLayout(fileDetails);

    auto* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->saveButton, 0, 0);
    //Coloring the buttons
    QPalette pal = this->saveButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::darkMagenta));
    this->saveButton->setAutoFillBackground(true);
    this->saveButton->setPalette(pal);
    this->saveButton->update();

    buttonsLayout->addWidget(this->userModeButton, 1, 0);
    QPalette pal2 = this->userModeButton->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::darkMagenta));
    this->userModeButton->setAutoFillBackground(true);
    this->userModeButton->setPalette(pal2);
    this->userModeButton->update();

    buttonsLayout->addWidget(this->adminModeButton, 2, 0);
    QPalette pal3 = this->adminModeButton->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::darkMagenta));
    this->adminModeButton->setAutoFillBackground(true);
    this->adminModeButton->setPalette(pal3);
    this->adminModeButton->update();

    mainLayout->addLayout(buttonsLayout);

    auto *mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveFileType);
    QObject::connect(this->userModeButton, &QPushButton::clicked, this, &GUI::startUserModeGUI);
    QObject::connect(this->adminModeButton, &QPushButton::clicked, this, &GUI::startAdminModeGUI);;
}

void GUI::startUserModeGUI() {
    if(type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    }
    else {
        this->setCursor(Qt::WaitCursor);
        auto* umg = new UserModeGUI{service, this->ASB};
//        umg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::startAdminModeGUI() {
    if (type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    } else {
        this->setCursor(Qt::WaitCursor);
        auto* amg = new AdminModeGUI{service};
    //        amg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::saveFileType() {
    this->type= this->filetypeComboBox->currentText().toStdString();
    if(this->type == "CSV File")
        this->ASB = new CSVShoppingBasket();
    else if(this->type == "HTML File")
        this->ASB = new HTMLShoppingBasket();
}

GUI::~GUI() {

}
