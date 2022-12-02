#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModelStyled;

class TableViewModelForStyledDelegates : public QAbstractTableModel
{
public:
    explicit TableViewModelForStyledDelegates(QObject* parent = 0);
    virtual ~TableViewModelForStyledDelegates();

    int columnCount(const QModelIndex& parent) const override;
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

private:
    QList<TestModelStyled> model;

};

} // namespace ViewModels
