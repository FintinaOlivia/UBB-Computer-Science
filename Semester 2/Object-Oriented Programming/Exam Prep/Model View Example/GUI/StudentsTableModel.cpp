//
// Created by Th on 15/06/2023.
//

#include <iostream>
#include "StudentsTableModel.h"

int StudentsTableModel::rowCount(const QModelIndex &parent) const {
    return this->repo.getStudents().size();
}

int StudentsTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant StudentsTableModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int column = index.column();
    Student currentStudent = this->repo.getStudents()[row];

    if(role == Qt::DisplayRole) {
        switch(column) {
            case 0:
                return QString::fromStdString(currentStudent.getName());
            case 1:
                return QString::fromStdString(currentStudent.getGroup());
            case 2:
                return QString::number(currentStudent.getLabGrade());
            case 3:
                return QString::number(currentStudent.getSeminarGrade());
            default:
                break;
        }
    }
    return QVariant();
}

QVariant StudentsTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
                case 0:
                    return QString("Name");
                case 1:
                    return QString("Group");
                case 2:
                    return QString("Lab Grade");
                case 3:
                    return QString("Seminar Grade");
                default:
                    break;
            }
        }
    }
    return QVariant();
}

bool StudentsTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role != Qt::EditRole)
        return false;
    else {
        int row = index.row();
        int column = index.column();

        Student &currentStudent = this->repo.getStudents()[row];

        if(role == Qt::EditRole) {
            switch (column) {
                case 0:
                    currentStudent.setName(value.toString().toStdString());
                    break;
                case 1:
                    break;
                case 2:
                    currentStudent.setLabGrade(value.toDouble());
                    break;
                case 3:
                    currentStudent.setSeminarGrade(value.toDouble());
                    break;
                default:
                    break;
            }
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags StudentsTableModel::flags(const QModelIndex& index) const {
    int column = index.column();
    if(column == 0 || column == 1)
        return Qt::ItemFlags {};
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void StudentsTableModel::addStudent(const Student &student) {
    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
    this->repo.add(student);
    this->endInsertRows();
}

void StudentsTableModel::deleteStudent(const Student &student) {
    this->beginRemoveRows(QModelIndex(), this->rowCount(), this->rowCount());
    this->repo.remove(student);
    this->endRemoveRows();

}
