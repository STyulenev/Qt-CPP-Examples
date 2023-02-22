#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModel;

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QList<double> columnWidths READ columnWidths NOTIFY columnWidthsChanged)

public:
    explicit TableModel(QObject* parent = 0);
    virtual ~TableModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    auto roleNames() const -> QHash<int, QByteArray> override;

    auto columnWidths() const -> const QList<double>&;

signals:
    void columnWidthsChanged();

private:
    QList<TestModel> model;
    QList<double> columnWidthList;

};

} // namespace ViewModels
