#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModelCustom;

class TableViewModelForCustomDelegates : public QAbstractTableModel
{
public:
    explicit TableViewModelForCustomDelegates(QObject* parent = 0);
    ~TableViewModelForCustomDelegates();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;

private:
    QVector<TestModelCustom> model;

};

} // namespace ViewModels
