#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModelStyled;

class TableViewModelForStyledDelegates : public QAbstractTableModel
{
public:
    explicit TableViewModelForStyledDelegates(QObject* parent = 0);
    virtual ~TableViewModelForStyledDelegates();

protected:
    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    virtual auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;

private:
    QVector<TestModelStyled> model;

};

} // namespace ViewModels
