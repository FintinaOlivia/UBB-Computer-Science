/********************************************************************************
** Form generated from reading UI file 'departmentgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTGUI_H
#define UI_DEPARTMENTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_departmentGUI
{
public:
    QPushButton *AddVolunteerToDepartmentButton;
    QLineEdit *nameInput;
    QLineEdit *emailInput;
    QLineEdit *interestsInput;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *addNewVolunteerButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *volunteersInDepartment;
    QListWidget *Description;
    QListWidget *volunteersWithNoDepartment;

    void setupUi(QWidget *departmentGUI)
    {
        if (departmentGUI->objectName().isEmpty())
            departmentGUI->setObjectName("departmentGUI");
        departmentGUI->resize(810, 513);
        AddVolunteerToDepartmentButton = new QPushButton(departmentGUI);
        AddVolunteerToDepartmentButton->setObjectName("AddVolunteerToDepartmentButton");
        AddVolunteerToDepartmentButton->setGeometry(QRect(610, 240, 101, 41));
        nameInput = new QLineEdit(departmentGUI);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(310, 240, 171, 31));
        emailInput = new QLineEdit(departmentGUI);
        emailInput->setObjectName("emailInput");
        emailInput->setGeometry(QRect(310, 280, 171, 31));
        interestsInput = new QLineEdit(departmentGUI);
        interestsInput->setObjectName("interestsInput");
        interestsInput->setGeometry(QRect(310, 320, 171, 31));
        label = new QLabel(departmentGUI);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 250, 41, 16));
        label_2 = new QLabel(departmentGUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 290, 31, 16));
        label_3 = new QLabel(departmentGUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 330, 47, 14));
        addNewVolunteerButton = new QPushButton(departmentGUI);
        addNewVolunteerButton->setObjectName("addNewVolunteerButton");
        addNewVolunteerButton->setGeometry(QRect(330, 370, 121, 41));
        widget = new QWidget(departmentGUI);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 782, 194));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        volunteersInDepartment = new QListWidget(widget);
        volunteersInDepartment->setObjectName("volunteersInDepartment");

        horizontalLayout->addWidget(volunteersInDepartment);

        Description = new QListWidget(widget);
        Description->setObjectName("Description");

        horizontalLayout->addWidget(Description);

        volunteersWithNoDepartment = new QListWidget(widget);
        volunteersWithNoDepartment->setObjectName("volunteersWithNoDepartment");

        horizontalLayout->addWidget(volunteersWithNoDepartment);


        retranslateUi(departmentGUI);
        QObject::connect(addNewVolunteerButton, SIGNAL(clicked()), departmentGUI, SLOT(addNewVolunteer()));
        QObject::connect(AddVolunteerToDepartmentButton, SIGNAL(clicked()), departmentGUI, SLOT(addExistingVolunteer()));

        QMetaObject::connectSlotsByName(departmentGUI);
    } // setupUi

    void retranslateUi(QWidget *departmentGUI)
    {
        departmentGUI->setWindowTitle(QCoreApplication::translate("departmentGUI", "departmentGUI", nullptr));
        AddVolunteerToDepartmentButton->setText(QCoreApplication::translate("departmentGUI", "Add Volunteer", nullptr));
        label->setText(QCoreApplication::translate("departmentGUI", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("departmentGUI", "Email:", nullptr));
        label_3->setText(QCoreApplication::translate("departmentGUI", "Interests:", nullptr));
        addNewVolunteerButton->setText(QCoreApplication::translate("departmentGUI", "Add New Volunteer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class departmentGUI: public Ui_departmentGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTGUI_H
