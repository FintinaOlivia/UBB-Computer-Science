/********************************************************************************
** Form generated from reading UI file 'studentswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSWIDGET_H
#define UI_STUDENTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentsWidget
{
public:
    QTableView *studentsTable;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *addNewStudentButton;
    QPushButton *pushButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameInput;
    QLineEdit *groupInput;
    QLineEdit *grade1Input;
    QLineEdit *grade2Input;

    void setupUi(QWidget *StudentsWidget)
    {
        if (StudentsWidget->objectName().isEmpty())
            StudentsWidget->setObjectName("StudentsWidget");
        StudentsWidget->resize(588, 517);
        studentsTable = new QTableView(StudentsWidget);
        studentsTable->setObjectName("studentsTable");
        studentsTable->setGeometry(QRect(70, 50, 491, 291));
        label = new QLabel(StudentsWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 360, 47, 14));
        label_2 = new QLabel(StudentsWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 390, 47, 14));
        label_3 = new QLabel(StudentsWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 420, 47, 14));
        label_4 = new QLabel(StudentsWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 450, 47, 14));
        widget = new QWidget(StudentsWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(370, 360, 121, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addNewStudentButton = new QPushButton(widget);
        addNewStudentButton->setObjectName("addNewStudentButton");

        verticalLayout->addWidget(addNewStudentButton);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        widget1 = new QWidget(StudentsWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(190, 360, 121, 111));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        nameInput = new QLineEdit(widget1);
        nameInput->setObjectName("nameInput");

        verticalLayout_2->addWidget(nameInput);

        groupInput = new QLineEdit(widget1);
        groupInput->setObjectName("groupInput");

        verticalLayout_2->addWidget(groupInput);

        grade1Input = new QLineEdit(widget1);
        grade1Input->setObjectName("grade1Input");

        verticalLayout_2->addWidget(grade1Input);

        grade2Input = new QLineEdit(widget1);
        grade2Input->setObjectName("grade2Input");

        verticalLayout_2->addWidget(grade2Input);

#if QT_CONFIG(shortcut)
        label->setBuddy(nameInput);
        label_2->setBuddy(groupInput);
        label_3->setBuddy(grade1Input);
        label_4->setBuddy(grade2Input);
#endif // QT_CONFIG(shortcut)

        retranslateUi(StudentsWidget);
        QObject::connect(addNewStudentButton, SIGNAL(clicked()), StudentsWidget, SLOT(addNewStudent()));
        QObject::connect(pushButton, SIGNAL(clicked()), StudentsWidget, SLOT(deleteStudent()));

        QMetaObject::connectSlotsByName(StudentsWidget);
    } // setupUi

    void retranslateUi(QWidget *StudentsWidget)
    {
        StudentsWidget->setWindowTitle(QCoreApplication::translate("StudentsWidget", "StudentsWidget", nullptr));
        label->setText(QCoreApplication::translate("StudentsWidget", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("StudentsWidget", "Group", nullptr));
        label_3->setText(QCoreApplication::translate("StudentsWidget", "Grade 1", nullptr));
        label_4->setText(QCoreApplication::translate("StudentsWidget", "Grade 2", nullptr));
        addNewStudentButton->setText(QCoreApplication::translate("StudentsWidget", "Add Student", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentsWidget", "Delete Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentsWidget: public Ui_StudentsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSWIDGET_H
