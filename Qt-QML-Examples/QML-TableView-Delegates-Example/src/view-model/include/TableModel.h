#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QList<double> columnWidths READ getColumnWidths CONSTANT)

private:
    struct TestModel {
        QString name;
        QString iconUrl;
        QString number;
        bool    status;
    };

    QList<TestModel> m_model;
    QList<double> m_columnWidthList;

public:
    explicit TableModel(QObject* parent = 0);
    virtual ~TableModel() = default;

    auto getColumnWidths() const -> const QList<double>&;

protected:
    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    virtual auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    virtual auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
