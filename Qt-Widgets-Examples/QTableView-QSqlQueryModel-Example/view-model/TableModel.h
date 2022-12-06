#pragma once

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace ViewModels {

class TableModel : public QSqlQueryModel
{
public:
    TableModel() = delete;
    TableModel(QString tableName);
    virtual ~TableModel();

    auto flags(const QModelIndex& index) const -> Qt::ItemFlags;
    auto setData(const QModelIndex& index, const QVariant& value,int role) -> bool;
    auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant;

    auto addColumn(const QString columnName, const QString columnType) -> void;
    auto deleteColumn(const QString columnName) -> void;

    auto addRow() -> void;
    auto deleteRow(int row) -> void;

    auto refresh() -> void;

private:
    QSqlDatabase db;
    QString tableName;

};

} // namespace ViewModels
