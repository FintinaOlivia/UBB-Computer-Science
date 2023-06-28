//
// Created by Th on 15/06/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_allDepartments.h" resolved

#include "alldepartments.h"
#include "ui_allDepartments.h"


allDepartments::allDepartments(Repository repository, QWidget *parent) :
        QWidget(parent), ui(new Ui::allDepartments) {
    ui->setupUi(this);
    this->repository = &repository;
    this->setWindowTitle("All departments statistics");
    this->sortDepartmentsByNumberOfVolunteers();
    this->populateList();
}

allDepartments::~allDepartments() {
    delete ui;
}

void allDepartments::sortDepartmentsByNumberOfVolunteers() {
    std::vector<Department> departments = repository->getDepartments();
    for (auto &department: departments) {
        departmentsWithNumberOfVolunteers.push_back({department.getName(), 0});
    }
    for (auto &volunteer: repository->getVolunteers()) {
        for (auto &department: departmentsWithNumberOfVolunteers) {
            if (volunteer.getDepartment() == department.name) {
                department.numberOfVolunteers++;
            }
        }
    }
    for(auto &department:departmentsWithNumberOfVolunteers) {
        std::sort(departmentsWithNumberOfVolunteers.begin(), departmentsWithNumberOfVolunteers.end(),
                  [](DepartmentWithNumberOfVolunteers a, DepartmentWithNumberOfVolunteers b) {
                      return a.numberOfVolunteers > b.numberOfVolunteers;
                  });
    }
}

void allDepartments::populateList() {
    ui->departmentWidget->clear();
    for (auto &department: departmentsWithNumberOfVolunteers) {
        ui->departmentWidget->addItem(QString::fromStdString(department.name + " " +
                                                      std::to_string(department.numberOfVolunteers)));
    }
}

