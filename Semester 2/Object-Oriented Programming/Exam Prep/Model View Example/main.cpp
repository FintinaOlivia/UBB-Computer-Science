#include <QApplication>
#include <QSortFilterProxyModel>
#include "Repository/Repository.h"
#include "GUI/studentswidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repo(R"(C:\Users\Th\CLionProjects\MV\Student.txt)");

    auto* model = new StudentsTableModel(repo);
    StudentsWidget mainTeacher(model);
    mainTeacher.setWindowTitle("Main Teacher");
    mainTeacher.show();

//    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel();
//    proxyModel->setSourceModel(model);
//    proxyModel->setFilterRegularExpression(QRegularExpression{"912"});
//    proxyModel->setFilterKeyColumn(1);
//    StudentsWidget teacher(proxyModel);

    StudentsWidget teacher(model);
    teacher.setWindowTitle("Teacher");
    teacher.show();

    return QApplication::exec();
}
