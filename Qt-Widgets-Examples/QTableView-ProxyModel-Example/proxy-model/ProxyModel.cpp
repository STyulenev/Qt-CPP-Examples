#include "ProxyModel.h"

namespace ProxyModels {

ProxyModel::ProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent),
      m_minId(0),
      m_maxId(99),
      m_status(Status::ALL)
{

}

void ProxyModel::setMinId(int minId)
{
    if (m_minId != minId)
        m_minId = minId;

    invalidateFilter();
}

void ProxyModel::setMaxId(int maxId)
{
    if (m_maxId != maxId)
        m_maxId = maxId;

    invalidateFilter();
}

void ProxyModel::setName(const QString &name)
{
    if (m_name != name)
        m_name = name;

    invalidateFilter();
}

void ProxyModel::setStatus(const Status status)
{
    if (m_status != status)
        m_status = status;

    invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const
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
            || !sourceModel()->data(indName).toString().startsWith(m_name, Qt::CaseInsensitive)
            || status) {
        return false;
    }

    return true;
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

} // namespace ProxyModels
