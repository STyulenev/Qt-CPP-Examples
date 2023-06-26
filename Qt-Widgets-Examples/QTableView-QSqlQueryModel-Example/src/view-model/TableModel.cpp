#include "TableModel.h"

namespace ViewModels {

TableModel::TableModel(QString tableName) :
    tableName(tableName)
{
    db = QSqlDatabase::addDatabase("QPSQL");

    db.setDatabaseName("localtest");
    db.setUserName("postgres");
    db.setHostName("localhost");
    db.setPassword("password");

    db.open();
    setQuery(QString("SELECT * FROM %1").arg(tableName));
}

TableModel::~TableModel()
{
    db.close();
}

auto TableModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable;
}

auto TableModel::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
        int id = data(primaryKeyIndex).toInt();

        QSqlQuery query(QString("UPDATE %1 SET %2 = '%3' WHERE id = %4")
                      .arg(tableName)
                      .arg(headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString())
                      .arg(value.toString())
                      .arg(id));
        query.exec();

        refresh();
    }

    return true;
}

auto TableModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;

    return QSqlQueryModel::data(index, role);
}

auto TableModel::addColumn(const QString columnName, const QString columnType) -> void
{
    QSqlQuery query(QString("ALTER TABLE %1 ADD %2 %3")
                    .arg(tableName)
                    .arg(columnName)
                    .arg(columnType));
    query.exec();

    refresh();
}

auto TableModel::deleteColumn(const QString columnName) -> void
{
    QSqlQuery query(QString("ALTER TABLE %1 DROP COLUMN %2")
                    .arg(tableName)
                    .arg(columnName));
    query.exec();

    refresh();
}

auto TableModel::addRow() -> void
{
    QSqlQuery query(QString("INSERT INTO %1 default VALUES").arg(tableName));
    query.exec();

    refresh();
}

auto TableModel::deleteRow(int row) -> void
{
    QSqlQuery query(QString("DELETE FROM %1 WHERE id = %2")
                    .arg(tableName)
                    .arg(QSqlQueryModel::index(row, 0).data().toInt()));
    query.exec();

    refresh();
}

auto TableModel::refresh() -> void
{
    clear();
    setQuery(QString("SELECT * FROM %1").arg(tableName));
}

} // namespace ViewModels
