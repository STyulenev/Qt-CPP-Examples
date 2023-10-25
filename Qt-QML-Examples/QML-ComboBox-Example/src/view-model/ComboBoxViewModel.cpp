#include "ComboBoxViewModel.h"

#include <QUrl>

namespace ViewModels {

ComboBoxViewModel::ComboBoxViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model = {
                { "Hamburger", "qrc:/res/images/hamburger.png" },
                { "Donut",     "qrc:/res/images/donut.png"     },
                { "Pizza",     "qrc:/res/images/pizza.png"     },
                { "Ice-cream", "qrc:/res/images/ice-cream.png" }
            };
}

auto ComboBoxViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto ComboBoxViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::DisplayRole:
        return model.at(index.row()).name;
    case Qt::DecorationRole:
        return QUrl(model.at(index.row()).iconUrl);
    default:
        return QVariant();
    }
}

auto ComboBoxViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto ComboBoxViewModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole]     = "DisplayRole";
    roles[Qt::DecorationRole]  = "DecorationRole";

    return roles;
}

} // namespace ViewModels
