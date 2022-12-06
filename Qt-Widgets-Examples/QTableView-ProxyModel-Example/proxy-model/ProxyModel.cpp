#include "ProxyModel.h"

namespace ProxyModels {

ProxyModel::ProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent),
      m_minId(0),
      m_maxId(99),
      m_status(Status::ALL)
{

}

auto ProxyModel::setMinId(int minId) -> void
{
    if (m_minId != minId)
        m_minId = minId;

    invalidateFilter();
}

auto ProxyModel::setMaxId(int maxId) -> void
{
    if (m_maxId != maxId)
        m_maxId = maxId;

    invalidateFilter();
}

auto ProxyModel::setName(const QString& name) -> void
{
    if (m_name != name)
        m_name = name;

    invalidateFilter();
}

auto ProxyModel::setStatus(const Status status) -> void
{
    if (m_status != status)
        m_status = status;

    invalidateFilter();
}

auto ProxyModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const -> bool
{
    const QModelIndex indMinId  = sourceModel()->index(source_row, 0, source_parent);
    const QModelIndex indMaxId  = sourceModel()->index(source_row, 0, source_parent);
    const QModelIndex indName   = sourceModel()->index(source_row, 1, source_parent);
    const QModelIndex indStatus = sourceModel()->index(source_row, 3, source_parent);

    bool status;
    switch (m_status) {
    case Status::ALL:
        status = false;
        break;
    case Status::TRUE:
        status = !(sourceModel()->data(indStatus).toBool());
        break;
    case Status::FALSE:
        status = (sourceModel()->data(indStatus).toBool());
        break;
    }

    if (sourceModel()->data(indMinId).toInt() < m_minId || sourceModel()->data(indMaxId).toInt() > m_maxId
            || !sourceModel()->data(indName).toString().startsWith(m_name, Qt::CaseInsensitive) || status) {
        return false;
    }

    return true;
}

auto ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    return sourceModel()->headerData(section, orientation, role);
}

} // namespace ProxyModels
