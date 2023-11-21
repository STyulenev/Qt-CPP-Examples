#include "TableViewModel.h"
#include "TableModel.h"

namespace ViewModels {

TableViewModel::TableViewModel(QObject* parent) :
    QObject(parent)
{
    m_horizontalHeaders = QStringList({ tr("id"), tr("name"), tr("number"), tr("status") });
    m_textAlignments = { Qt::AlignCenter, Qt::AlignCenter, Qt::AlignCenter, Qt::AlignCenter };
    m_columnWidths = { 0.1, 0.35, 0.35, 0.2 };

    m_tableModel = new TableModel(this);
}

auto TableViewModel::getHorizontalHeaders() const -> const QStringList&
{
    return m_horizontalHeaders;
}

auto TableViewModel::getColumnWidths() const -> const QList<double>&
{
    return m_columnWidths;
}

auto TableViewModel::getTextAlignments() const -> const QList<int>&
{
    return m_textAlignments;
}

auto TableViewModel::getTableModel() const -> QAbstractTableModel*
{
    return m_tableModel;
}

} // namespace ViewModels
