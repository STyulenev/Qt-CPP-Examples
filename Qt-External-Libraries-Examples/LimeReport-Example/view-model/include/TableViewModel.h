#pragma once

#include <QAbstractTableModel>

struct TestModel {
    int id;
    QString name;
    QString number;
    bool status;
};

class TableViewModel : public QAbstractTableModel
{
public:
    explicit TableViewModel(QObject* parent = 0);
    virtual ~TableViewModel();

    auto columnCount(const QModelIndex& parent) const  -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;

private:
    QList<TestModel> model;

};

