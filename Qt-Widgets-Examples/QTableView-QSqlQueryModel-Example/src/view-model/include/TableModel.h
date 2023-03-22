#pragma once

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace ViewModels {

/*!
 * \brief The TableModel class
 * \details Sql script:
 * CREATE DATABASE localtest;
 *
 * CREATE TABLE test
 * (
 *     id serial NOT NULL,
 *     two boolean,
 *     three character varying(200),
 *     four integer,
 *     five time without time zone,
 *     six double precision
 * );
 */
class TableModel : public QSqlQueryModel
{
public:
    TableModel() = delete;
    TableModel(QString tableName);
    virtual ~TableModel();

    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto setData(const QModelIndex& index, const QVariant& value,int role) -> bool override;
    virtual auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant override;

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
