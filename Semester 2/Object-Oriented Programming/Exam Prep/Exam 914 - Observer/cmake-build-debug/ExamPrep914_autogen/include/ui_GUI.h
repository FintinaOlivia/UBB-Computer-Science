/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QListWidget *Description;
    QListWidget *VolunteersInDept;
    QListWidget *PotentialVolunteers;
    QPushButton *AddVolunteerButton;
    QLineEdit *NameOfVolunteer;
    QLineEdit *EmailAddressVolunteer;
    QLineEdit *InterestsOfVolunteer;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName("GUI");
        GUI->resize(879, 567);
        Description = new QListWidget(GUI);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(300, 40, 241, 171));
        VolunteersInDept = new QListWidget(GUI);
        VolunteersInDept->setObjectName("VolunteersInDept");
        VolunteersInDept->setGeometry(QRect(30, 40, 251, 171));
        PotentialVolunteers = new QListWidget(GUI);
        PotentialVolunteers->setObjectName("PotentialVolunteers");
        PotentialVolunteers->setGeometry(QRect(560, 40, 256, 171));
        AddVolunteerButton = new QPushButton(GUI);
        AddVolunteerButton->setObjectName("AddVolunteerButton");
        AddVolunteerButton->setGeometry(QRect(350, 360, 121, 31));
        NameOfVolunteer = new QLineEdit(GUI);
        NameOfVolunteer->setObjectName("NameOfVolunteer");
        NameOfVolunteer->setGeometry(QRect(320, 240, 191, 31));
        EmailAddressVolunteer = new QLineEdit(GUI);
        EmailAddressVolunteer->setObjectName("EmailAddressVolunteer");
        EmailAddressVolunteer->setGeometry(QRect(320, 280, 191, 31));
        InterestsOfVolunteer = new QLineEdit(GUI);
        InterestsOfVolunteer->setObjectName("InterestsOfVolunteer");
        InterestsOfVolunteer->setGeometry(QRect(320, 320, 191, 31));
        pushButton = new QPushButton(GUI);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 230, 101, 31));
        label = new QLabel(GUI);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 250, 41, 21));
        label_2 = new QLabel(GUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 290, 31, 16));
        label_3 = new QLabel(GUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 330, 47, 14));

        retranslateUi(GUI);
        QObject::connect(AddVolunteerButton, SIGNAL(clicked()), GUI, SLOT(addNewVolunteer()));

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        AddVolunteerButton->setText(QCoreApplication::translate("GUI", "Add New Volunteer", nullptr));
        NameOfVolunteer->setText(QString());
        pushButton->setText(QCoreApplication::translate("GUI", "Add Volunteer", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Email:", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "Interests:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
