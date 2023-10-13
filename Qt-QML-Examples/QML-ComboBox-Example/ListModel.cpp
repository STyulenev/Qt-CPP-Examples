#include "ListModel.h"

#include <QUrl>

namespace ViewModels {

ListModel::ListModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model = {
                { "Hamburger" },

                { "Donut" },

                { "Pizza" },

                { "Ice-cream" }
            };
}

auto ListModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto ListModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::DisplayRole:
        return model.at(index.row()).name;
    /*case Role::DescriptionRole:
        return model.at(index.row()).description;
    case Role::StatusRole:
        return model.at(index.row()).status;
    case Qt::DecorationRole:
        return QUrl(model.at(index.row()).iconUrl);
    case Qt::ToolTipRole:
        return "User status here\nYou can change it";*/
    }

    return QVariant();
}

auto ListModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto ListModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole]     = "DisplayRole";
    /*roles[Qt::DecorationRole]  = "DecorationRole";
    roles[Qt::ToolTipRole]     = "ToolTipRole";

    roles[Role::DescriptionRole] = "DescriptionRole";
    roles[Role::StatusRole]      = "StatusRole";*/

    return roles;
}

} // namespace ViewModels
