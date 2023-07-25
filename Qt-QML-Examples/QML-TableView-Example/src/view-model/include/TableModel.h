#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QStringList horizontalHeaders READ getHorizontalHeaders CONSTANT)
    Q_PROPERTY(QList<double> columnWidths READ getColumnWidths CONSTANT)
    Q_PROPERTY(QList<int> textAlignments READ getTextAlignments CONSTANT)

private:
    struct TestModel {
        int id;
        QString name;
        QString number;
        QString status;
    };

    QList<TestModel> m_model;

    QStringList m_horizontalHeaders;
    QList<int> m_textAlignments;
    QList<double> m_columnWidths;

public:
    explicit TableModel(QObject* parent = 0);
    virtual ~TableModel() = default;

    auto getHorizontalHeaders() const -> const QStringList&;
    auto getColumnWidths() const -> const QList<double>&;
    auto getTextAlignments() const -> const QList<int>&;

protected:
    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
