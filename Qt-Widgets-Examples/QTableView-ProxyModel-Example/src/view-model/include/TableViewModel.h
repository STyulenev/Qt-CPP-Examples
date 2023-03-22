#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModel;

class TableViewModel : public QAbstractTableModel
{
public:
    explicit TableViewModel(QObject* parent = 0);
    virtual ~TableViewModel();

    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    QVector<TestModel> model;

};

} // namespace ViewModels
