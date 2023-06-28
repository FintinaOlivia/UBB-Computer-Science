/********************************************************************************
** Form generated from reading UI file 'departmentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTWINDOW_H
#define UI_DEPARTMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_departmentWindow
{
public:
    QListWidget *VolunteersInDept;
    QPushButton *pushButton;
    QListWidget *PotentialVolunteers;
    QLineEdit *EmailAddressVolunteer;
    QLabel *label_2;
    QPushButton *AddVolunteerButton;
    QLabel *label;
    QLabel *label_3;
    QListWidget *Description;
    QLineEdit *InterestsOfVolunteer;
    QLineEdit *NameOfVolunteer;

    void setupUi(QWidget *departmentWindow)
    {
        if (departmentWindow->objectName().isEmpty())
            departmentWindow->setObjectName("departmentWindow");
        departmentWindow->resize(808, 613);
        VolunteersInDept = new QListWidget(departmentWindow);
        VolunteersInDept->setObjectName("VolunteersInDept");
        VolunteersInDept->setGeometry(QRect(190, 190, 251, 171));
        pushButton = new QPushButton(departmentWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 380, 101, 31));
        PotentialVolunteers = new QListWidget(departmentWindow);
        PotentialVolunteers->setObjectName("PotentialVolunteers");
        PotentialVolunteers->setGeometry(QRect(720, 190, 256, 171));
        EmailAddressVolunteer = new QLineEdit(departmentWindow);
        EmailAddressVolunteer->setObjectName("EmailAddressVolunteer");
        EmailAddressVolunteer->setGeometry(QRect(480, 430, 191, 31));
        label_2 = new QLabel(departmentWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 440, 31, 16));
        AddVolunteerButton = new QPushButton(departmentWindow);
        AddVolunteerButton->setObjectName("AddVolunteerButton");
        AddVolunteerButton->setGeometry(QRect(510, 510, 121, 31));
        label = new QLabel(departmentWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 400, 41, 21));
        label_3 = new QLabel(departmentWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 480, 47, 14));
        Description = new QListWidget(departmentWindow);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(460, 190, 241, 171));
        InterestsOfVolunteer = new QLineEdit(departmentWindow);
        InterestsOfVolunteer->setObjectName("InterestsOfVolunteer");
        InterestsOfVolunteer->setGeometry(QRect(480, 470, 191, 31));
        NameOfVolunteer = new QLineEdit(departmentWindow);
        NameOfVolunteer->setObjectName("NameOfVolunteer");
        NameOfVolunteer->setGeometry(QRect(480, 390, 191, 31));

        retranslateUi(departmentWindow);

        QMetaObject::connectSlotsByName(departmentWindow);
    } // setupUi

    void retranslateUi(QWidget *departmentWindow)
    {
        departmentWindow->setWindowTitle(QCoreApplication::translate("departmentWindow", "departmentWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("departmentWindow", "Add Volunteer", nullptr));
        label_2->setText(QCoreApplication::translate("departmentWindow", "Email:", nullptr));
        AddVolunteerButton->setText(QCoreApplication::translate("departmentWindow", "Add New Volunteer", nullptr));
        label->setText(QCoreApplication::translate("departmentWindow", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("departmentWindow", "Interests:", nullptr));
        NameOfVolunteer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class departmentWindow: public Ui_departmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTWINDOW_H
