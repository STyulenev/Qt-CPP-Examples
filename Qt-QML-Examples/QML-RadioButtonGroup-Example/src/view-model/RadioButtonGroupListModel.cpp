#include "RadioButtonGroupListModel.h"

#include <QDebug>

namespace ViewModels {

RadioButtonGroupListModel::RadioButtonGroupListModel(const QStringList& options, const int currentItem, QObject* parent) :
    QAbstractListModel(parent),
    currentItem(currentItem)
{
    listData.resize(options.size());

    for (int i = 0; i < options.size(); ++i) {
        listData[i].text = options.at(i);
        listData[i].enabled = true;
        listData[i].checked = (i == currentItem);
    }
}

auto RadioButtonGroupListModel::getCurrentItem() const -> int
{
    return currentItem;
}

auto RadioButtonGroupListModel::setCurrentItem(int newCurrentItem) -> void
{
    currentItem = newCurrentItem;
}

auto RadioButtonGroupListModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return listData.size();
}

auto RadioButtonGroupListModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable;
}

auto RadioButtonGroupListModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole:
        return listData[index.row()].text;
    case Role::EnabledRole:
        return listData[index.row()].enabled;
    case Role::CheckedRole:
        return listData[index.row()].checked;
    default:
        qFatal("unknown role");
    }

    return QVariant();
}

auto RadioButtonGroupListModel::setData(const QModelIndex& index, [[maybe_unused]] const QVariant& value, int role) -> bool
{
    switch (role) {
    case Qt::EditRole:
        std::swap(listData[currentItem].checked, listData[index.row()].checked);
        currentItem = index.row();
    /*default:
        qFatal("unknown role");*/
    }

    return true;
}

auto RadioButtonGroupListModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole]  = "DisplayRole";
    roles[Role::EnabledRole] = "EnabledRole";
    roles[Role::CheckedRole] = "CheckedRole";
    roles[Qt::EditRole] = "EditRole";

    return roles;
}


} // namespace ViewModels
