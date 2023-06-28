//
// Created by Th on 15/06/2023.
//

#ifndef EXAMPREP914_ALLDEPARTMENTS_H
#define EXAMPREP914_ALLDEPARTMENTS_H

#include <QWidget>
#include "Repository.h"


QT_BEGIN_NAMESPACE
namespace Ui { class allDepartments; }
QT_END_NAMESPACE

class allDepartments : public QWidget {
Q_OBJECT

public:
    explicit allDepartments(Repository repository, QWidget *parent = nullptr);

    ~allDepartments() override;

    struct {
        std::string name;
        int numberOfVolunteers;
    } typedef DepartmentWithNumberOfVolunteers;


private:
    Ui::allDepartments *ui;
    Repository* repository;
    void sortDepartmentsByNumberOfVolunteers();
    std::vector<DepartmentWithNumberOfVolunteers> departmentsWithNumberOfVolunteers;
    void populateList();
};


#endif //EXAMPREP914_ALLDEPARTMENTS_H
