#include "ListModel.h"

#include <QUrl>

namespace ViewModels {

struct TestModel {
    QString name;
    QString image;
    int     weight;
    double  price;
};

ListModel::ListModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model = {
        { "Buns",         "qrc:/res/images/buns.png",          420,  4.10  },
        { "Chicken",      "qrc:/res/images/chicken.png",       2200, 8.99  },
        { "Donut",        "qrc:/res/images/donut.png",         110,  0.99  },
        { "Fish",         "qrc:/res/images/fish.png",          360,  3.49  },
        { "French-fries", "qrc:/res/images/french-fries.png",  80,   1.09  },
        { "Hamburger",    "qrc:/res/images/hamburger.png",     480,  3.99  },
        { "Ice-cream",    "qrc:/res/images/ice-cream.png",     250,  2.20  },
        { "Pizza",        "qrc:/res/images/pizza.png",         1150, 5.45  },
        { "Sandwich",     "qrc:/res/images/sandwich.png",      390,  2.99  },
        { "Steak",        "qrc:/res/images/steak.png",         1000, 12.50 },
        { "Sushi",        "qrc:/res/images/sushi.png",         600,  7.99  },
        { "Taco",         "qrc:/res/images/taco.png",          460,  3.15  },
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
    case Qt::DecorationRole:
        return QUrl(model.at(index.row()).image);
    case Role::WeightRole:
        return model.at(index.row()).weight;
    case Role::PriceRole:
        return model.at(index.row()).price;
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

    roles[Qt::DisplayRole]    = "DisplayRole";
    roles[Qt::DecorationRole] = "DecorationRole";
    roles[Role::WeightRole]   = "WeightRole";
    roles[Role::PriceRole]    = "PriceRole";

    return roles;
}

} // namespace ViewModels
