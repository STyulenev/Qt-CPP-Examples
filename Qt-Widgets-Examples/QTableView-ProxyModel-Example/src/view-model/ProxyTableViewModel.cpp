#include "ProxyTableViewModel.h"

namespace ProxyModels {

ProxyTableViewModel::ProxyTableViewModel(QObject* parent) :
    QSortFilterProxyModel(parent),
    m_minId(0),
    m_maxId(99),
    m_status(Status::ALL)
{

}

auto ProxyTableViewModel::setMinId(int minId) -> void
{
    if (m_minId != minId)
        m_minId = minId;

    count = 0;
    sumAge = 0;

    invalidateFilter();

    emit dataReady(count, sumAge);
}

auto ProxyTableViewModel::setMaxId(int maxId) -> void
{
    if (m_maxId != maxId)
        m_maxId = maxId;

    count = 0;
    sumAge = 0;

    invalidateFilter();

    emit dataReady(count, sumAge);
}

auto ProxyTableViewModel::setName(const QString& name) -> void
{
    if (m_name != name)
        m_name = name;

    count = 0;
    sumAge = 0;

    invalidateFilter();

    emit dataReady(count, sumAge);
}

auto ProxyTableViewModel::setStatus(const Status& status) -> void
{
    if (m_status != status)
        m_status = status;

    count = 0;
    sumAge = 0;

    invalidateFilter();

    emit dataReady(count, sumAge);
}

auto ProxyTableViewModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const -> bool
{
    const QModelIndex indMinId  = sourceModel()->index(source_row, 0, source_parent);
    const QModelIndex indMaxId  = sourceModel()->index(source_row, 0, source_parent);
    const QModelIndex indName   = sourceModel()->index(source_row, 1, source_parent);
    const QModelIndex indAge    = sourceModel()->index(source_row, 2, source_parent);
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

    count++;
    sumAge += sourceModel()->data(indAge).toInt();

    return true;
}

auto ProxyTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    return sourceModel()->headerData(section, orientation, role);
}

auto ProxyTableViewModel::lessThan(const QModelIndex& sourceLeft, const QModelIndex& sourceRight) const -> bool
{
    // Простейший пример переопределения метода сравнения QSortFilterProxyModel::lessThan
    const QVariant dataLeft = sourceLeft.data();
    const QVariant dataRight = sourceRight.data();

    switch (sourceLeft.column()) {
    case 0:
        return dataLeft.toInt() < dataRight.toInt();
    case 1:
        return dataLeft.toString() < dataRight.toString();
    case 2:
        return dataLeft.toInt() < dataRight.toInt();
    case 3:
        return dataLeft.toBool() < dataRight.toBool();
    [[unlikely]] default: assert(!"Should not get here");
    }

    return QSortFilterProxyModel::lessThan(sourceLeft, sourceRight);
}

} // namespace ProxyTableViewModels
