#pragma once

#include <QAbstractTableModel>

struct TestModel;

class TableViewModel : public QAbstractTableModel
{
public:
    explicit TableViewModel(QObject* parent = 0);
    virtual ~TableViewModel();

    int columnCount(const QModelIndex& parent) const override;
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;


private:
    QList<TestModel> model;

};

