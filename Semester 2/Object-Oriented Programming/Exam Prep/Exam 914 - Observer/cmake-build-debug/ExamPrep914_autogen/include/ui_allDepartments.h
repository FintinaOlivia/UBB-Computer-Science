/********************************************************************************
** Form generated from reading UI file 'alldepartments.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLDEPARTMENTS_H
#define UI_ALLDEPARTMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_allDepartments
{
public:
    QListWidget *departmentWidget;

    void setupUi(QWidget *allDepartments)
    {
        if (allDepartments->objectName().isEmpty())
            allDepartments->setObjectName("allDepartments");
        allDepartments->resize(481, 364);
        departmentWidget = new QListWidget(allDepartments);
        departmentWidget->setObjectName("departmentWidget");
        departmentWidget->setGeometry(QRect(70, 40, 256, 192));

        retranslateUi(allDepartments);

        QMetaObject::connectSlotsByName(allDepartments);
    } // setupUi

    void retranslateUi(QWidget *allDepartments)
    {
        allDepartments->setWindowTitle(QCoreApplication::translate("allDepartments", "allDepartments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class allDepartments: public Ui_allDepartments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLDEPARTMENTS_H
