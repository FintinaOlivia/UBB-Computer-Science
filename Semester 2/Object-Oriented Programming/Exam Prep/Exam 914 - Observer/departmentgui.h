//
// Created by Th on 14/06/2023.
//

#ifndef EXAMPREP914_DEPARTMENTGUI_H
#define EXAMPREP914_DEPARTMENTGUI_H

#include <QWidget>
#include "Repository.h"


QT_BEGIN_NAMESPACE
namespace Ui { class departmentGUI; }
QT_END_NAMESPACE

class departmentGUI : public QWidget, public Observer {
Q_OBJECT

public:
    explicit departmentGUI(Department department,
                           Repository* repository,
                           QWidget *parent = nullptr);
    void update() override;
    ~departmentGUI() override;

public slots:
    void addNewVolunteer();
    void addExistingVolunteer();

private:
    Ui::departmentGUI *ui;
    Repository* repository;
    Department department;

    void populateList();

};


#endif //EXAMPREP914_DEPARTMENTGUI_H
