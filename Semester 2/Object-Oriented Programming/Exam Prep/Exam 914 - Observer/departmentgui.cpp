//
// Created by Th on 14/06/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_departmentGUI.h" resolved

#include <sstream>
#include <QMessageBox>
#include <iostream>
#include "departmentgui.h"
#include "ui_departmentGUI.h"


departmentGUI::departmentGUI(Department department, Repository *repository, QWidget *parent) {
    ui = new Ui::departmentGUI;
    ui->setupUi(this);
    this->department = department;
    this->repository = repository;
    this->setWindowTitle(QString::fromStdString(department.getName()));
    populateList();
}

departmentGUI::~departmentGUI() {
    delete ui;
}

void departmentGUI::populateList() {
    ui->volunteersInDepartment->clear();
    for (auto &volunteer: repository->getVolunteers()) {
        if (volunteer.getDepartment() == department.getName()) {
            ui->volunteersInDepartment->addItem(QString::fromStdString(volunteer.getName()));
        }
    }

    ui->volunteersWithNoDepartment->clear();
    for (auto &volunteer: repository->getVolunteers()) {
        if (volunteer.getDepartment() == "-") {
            ui->volunteersWithNoDepartment->addItem(QString::fromStdString(volunteer.getName()));
        }
    }

    ui->Description->addItem(QString::fromStdString(department.getDescription()));
}

void departmentGUI::addNewVolunteer() {
    auto volunteerName = ui->nameInput->text().toStdString();
    auto volunteerEmail = ui->emailInput->text().toStdString();
    if(volunteerName.empty() || volunteerEmail.empty()){
        QMessageBox::critical(this, "Error", "Field cannot be empty");
    }
    auto volunteerInterests = ui->interestsInput->text().toStdString();

    std::vector<std::string> interests;
    std::stringstream ss(volunteerInterests);
    std::string interest;
    while (getline(ss, interest, ',')) {
        interests.push_back(interest);
    }

    Volunteer volunteer(volunteerName, volunteerEmail, interests, "-");
    repository->addVolunteer(volunteer);
}

void departmentGUI::update() {
    populateList();
}

void departmentGUI::addExistingVolunteer() {
    auto volunteerName = ui->volunteersWithNoDepartment->currentItem()->text().toStdString();
    auto volunteerEmail = ui->volunteersWithNoDepartment->currentItem()->text().toStdString();
    auto volunteerInterests = ui->volunteersWithNoDepartment->currentItem()->text().toStdString();

    std::vector<std::string> interests;
    std::stringstream ss(volunteerInterests);
    std::string interest;
    while (getline(ss, interest, ',')) {
        interests.push_back(interest);
    }

    Volunteer volunteer(volunteerName, volunteerEmail, interests, "-");
    Volunteer newVolunteer(volunteerName, volunteerEmail, interests, department.getName());
    repository->deleteVolunteer(volunteer);
    repository->addVolunteer(newVolunteer);
    repository->notify();

}


