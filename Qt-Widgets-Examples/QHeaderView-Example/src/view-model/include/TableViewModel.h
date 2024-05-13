#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModel;

class TableViewModel : public QAbstractTableModel
{

public:
    explicit TableViewModel(QObject* parent = 0);
    ~TableViewModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role = Qt::EditRole) -> bool override;

private:
    QVector<TestModel> model;

};

} // namespace ViewModels
