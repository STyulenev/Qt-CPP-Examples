#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModel;

class TableViewModel : public QAbstractTableModel
{
private:
    QList<TestModel> model;

public:
    explicit TableViewModel(QObject* parent = 0);
    virtual ~TableViewModel();

protected:
    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    virtual auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    virtual auto insertRows(int position, int rows, const QModelIndex& parent = QModelIndex()) -> bool override;
    virtual auto removeRows(int position, int rows, const QModelIndex& parent = QModelIndex()) -> bool override;

};

} // namespace ViewModels
