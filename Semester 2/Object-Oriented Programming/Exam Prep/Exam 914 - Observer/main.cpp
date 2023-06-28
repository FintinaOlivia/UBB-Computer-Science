#include <QApplication>
#include <QPushButton>
#include "Repository.h"
#include "departmentgui.h"
#include "alldepartments.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<departmentGUI*> departments;

    auto repository = new Repository();
    for(const Department& department:repository->getDepartments()){
        departmentGUI* newDepartment = new departmentGUI(department, repository);
        departments.push_back(newDepartment);
        repository->registerObserver(newDepartment);
    }

    for(auto department:departments){
        department->show();
    }

    auto allDepartmentsStats = new allDepartments(*repository);
    allDepartmentsStats->show();

    return a.exec();
}
