#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

class TableViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList horizontalHeaders READ getHorizontalHeaders CONSTANT)
    Q_PROPERTY(QList<double> columnWidths READ getColumnWidths CONSTANT)
    Q_PROPERTY(QList<int> textAlignments  READ getTextAlignments CONSTANT)
    Q_PROPERTY(QAbstractTableModel* tableModel READ getTableModel NOTIFY tableModelChanged)

private:
    QStringList          m_horizontalHeaders;
    QList<int>           m_textAlignments;
    QList<double>        m_columnWidths;
    QAbstractTableModel* m_tableModel;

public:
    explicit TableViewModel(QObject* parent = 0);
    virtual ~TableViewModel() = default;

    auto getHorizontalHeaders() const -> const QStringList&;
    auto getColumnWidths() const -> const QList<double>&;
    auto getTextAlignments() const -> const QList<int>&;
    auto getTableModel() const -> QAbstractTableModel*;

signals:
    auto tableModelChanged() -> void;

};

} // namespace ViewModels
