//
// Created by Th on 15/06/2023.
//

#ifndef MV_STUDENTSTABLEMODEL_H
#define MV_STUDENTSTABLEMODEL_H


#include <QAbstractTableModel>
#include "../Repository/Repository.h"

class StudentsTableModel : public QAbstractTableModel {
private:
    Repository& repo;

public:
    StudentsTableModel(Repository& repo, QObject* parent = nullptr) : repo(repo) {};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void addStudent(const Student& student);
    void deleteStudent(const Student& student);
};


#endif //MV_STUDENTSTABLEMODEL_H
