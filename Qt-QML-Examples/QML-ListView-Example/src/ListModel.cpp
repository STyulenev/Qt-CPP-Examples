#include "ListModel.h"

#include <QUrl>

namespace ViewModels {

struct TestModel {
    QString name;
    QString iconUrl;
    QString description;
    bool status;
};

ListModel::ListModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model = { { "Hamburger", "qrc:/images/hamburger.png", "A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat,"
                " typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce, tomato, onion, pickles, bacon,"
                " or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \"special sauce\".", true },
              { "Donut", "qrc:/images/donut.png", "A doughnut or donut is a type of food made from leavened fried dough. It is popular in many countries and"
                " is prepared in various forms as a sweet snack that can be homemade or purchased in bakeries, supermarkets, food stalls, and franchised"
                " specialty vendors. Doughnut is the traditional spelling, while donut is the simplified version; the terms are used interchangeably.", false },
              { "Pizza", "qrc:/images/pizza.png", "Pizza is a dish of Italian origin consisting of a usually round, flat base of leavened wheat-based"
                " dough topped with tomatoes, cheese, and often various other ingredients (such as various types of sausage, anchovies, mushrooms, onions,"
                " olives, vegetables, meat, ham, etc.), which is then baked at a high temperature, traditionally in a wood-fired oven. A small pizza is"
                " sometimes called a pizzetta.", true },
              { "Ice-cream", "qrc:/images/ice-cream.png", "Ice cream is a sweetened frozen food typically eaten as a snack or dessert. It may be made from"
                " milk or cream and is flavoured with a sweetener, either sugar or an alternative, and a spice, such as cocoa or vanilla, or with fruit"
                " such as strawberries or peaches. It can also be made by whisking a flavored cream base and liquid nitrogen together. Food coloring is"
                " sometimes added, in addition to stabilizers.", false }
            };
}

ListModel::~ListModel()
{

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
    case Role::DescriptionRole:
        return model.at(index.row()).description;
    case Role::StatusRole:
        return model.at(index.row()).status;
    case Qt::DecorationRole:
        return QUrl(model.at(index.row()).iconUrl);
    case Qt::ToolTipRole:
        return "User status here\nYou can change it";
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
    roles[Qt::DecorationRole]  = "DecorationRole";
    roles[Qt::ToolTipRole]     = "ToolTipRole";

    roles[Role::DescriptionRole] = "DescriptionRole";
    roles[Role::StatusRole]      = "StatusRole";

    return roles;
}

} // namespace ViewModels
