#include "SomeModel.h"

#include <QUrl>

SomeModel::SomeModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model.append(new Models::TestModel("Hamburger", "qrc:/res/images/hamburger.png", this));
    model.append(new Models::TestModel("Donut",     "qrc:/res/images/donut.png",     this));
    model.append(new Models::TestModel("Pizza",     "qrc:/res/images/pizza.png",     this));
    model.append(new Models::TestModel("Ice-cream", "qrc:/res/images/ice-cream.png", this));
}

auto SomeModel::rowCount([[maybe_unused]] const QModelIndex &index) const -> int
{
    return model.length();
}

auto SomeModel::data(const QModelIndex &index, int role) const -> QVariant
{
    switch (role) {
    case Qt::DisplayRole:
        return QVariant::fromValue(model.at(index.row()));
    }

    return QVariant();
}

auto SomeModel::flags([[maybe_unused]] const QModelIndex &index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto SomeModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole] = "display";

    return roles;
}
