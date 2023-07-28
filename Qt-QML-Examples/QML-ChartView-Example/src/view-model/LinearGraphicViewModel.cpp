#include "LinearGraphicViewModel.h"

#include <QUrl>

namespace ViewModels {

LinearGraphicViewModel::LinearGraphicViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

LinearGraphicViewModel::LinearGraphicViewModel(const QVector<std::pair<double, double>>& data, QObject* parent)
    : QAbstractTableModel(parent),
      m_data(data)
{

}

auto LinearGraphicViewModel::columnCount(const QModelIndex& parent) const -> int
{
    return 2;
}

auto LinearGraphicViewModel::rowCount(const QModelIndex& parent) const -> int
{
    return m_data.length();
}

auto LinearGraphicViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0:
            return m_data.at(index.row()).first;
        case 1:
            return m_data.at(index.row()).second;
        default:
            return QVariant();
        }
    // other roles
    }

    return QVariant();
}

auto LinearGraphicViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

} // namespace ViewModels
