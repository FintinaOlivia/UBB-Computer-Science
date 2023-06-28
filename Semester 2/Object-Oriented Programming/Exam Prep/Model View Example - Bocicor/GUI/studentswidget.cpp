//
// Created by Th on 15/06/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StudentsWidget.h" resolved

#include "studentswidget.h"
#include <QTableWidget>
#include "ui_StudentsWidget.h"


StudentsWidget::StudentsWidget(StudentsTableModel* model, QWidget *parent) :
         QWidget(parent), ui(new Ui::StudentsWidget), smodel{model} {

    ui->setupUi(this);
    ui->studentsTable->setModel(smodel);
}

StudentsWidget::~StudentsWidget() {
    delete ui;
}

void StudentsWidget::addNewStudent() {
    std::string name = ui->nameInput->text().toStdString();
    std::string group = ui->groupInput->text().toStdString();
    double grade1 = ui->grade1Input->text().toDouble();
    double grade2 = ui->grade2Input->text().toDouble();

    Student student{name, group, grade1, grade2};
    smodel->addStudent(student);

}

void StudentsWidget::deleteStudent() {
    std::string name = ui->nameInput->text().toStdString();
    std::string group = ui->groupInput->text().toStdString();
    double grade1 = ui->grade1Input->text().toDouble();
    double grade2 = ui->grade2Input->text().toDouble();

    Student student{name, group, grade1, grade2};
    smodel->deleteStudent(student);

}
