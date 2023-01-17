#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

struct TestModel;

class TableModel : public QAbstractTableModel
{

    Q_OBJECT
    Q_PROPERTY(QStringList horizontalHeaders READ horizontalHeaders NOTIFY horizontalHeadersChanged)
    Q_PROPERTY(QList<int> textAlignments READ textAlignments NOTIFY textAlignmentsChanged)
    Q_PROPERTY(QList<double> columnWidths READ columnWidths NOTIFY columnWidthsChanged)

public:
    explicit TableModel(QObject* parent = 0);
    virtual ~TableModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    /*Q_INVOKABLE*/ auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    auto roleNames() const -> QHash<int, QByteArray> override;

    const QStringList& horizontalHeaders() const {
        return horizontalHeaderList;
    }

    const QList<double>& columnWidths() const {
        return columnWidthList;
    }

    const QList<int>& textAlignments() const {
        return textAlignmentList;
    }

signals:
    void horizontalHeadersChanged();
    void textAlignmentsChanged();
    void columnWidthsChanged();

private:
    QList<TestModel> model;

    QStringList horizontalHeaderList;
    QList<int> textAlignmentList;
    QList<double> columnWidthList;

};

} // namespace ViewModels
