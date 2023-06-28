//
// Created by Th on 15/06/2023.
//

#ifndef MV_STUDENTSWIDGET_H
#define MV_STUDENTSWIDGET_H

#include <QWidget>
#include "StudentsTableModel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class StudentsWidget; }
QT_END_NAMESPACE

class StudentsWidget : public QWidget {
Q_OBJECT

public:
    StudentsWidget(StudentsTableModel* model, QWidget *parent = nullptr);
    ~StudentsWidget() override;

    public slots:
        void addNewStudent();
        void deleteStudent();

private:
    Ui::StudentsWidget *ui;
    StudentsTableModel* smodel;
};


#endif //MV_STUDENTSWIDGET_H
