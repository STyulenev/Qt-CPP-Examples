#include "DishListModel.h"

namespace ViewModels {

DishListModel::DishListModel(QObject* parent) :
    QObject(parent)
{
    Models::DishModel* hamburger = new Models::DishModel(this);
    hamburger->setName("Hamburger");
    hamburger->setIconUrl("qrc:/res/images/hamburger.png");
    hamburger->setDescription("A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat,"
        "typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce,"
        "tomato, onion, pickles, bacon, or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \"special sauce\".");
    hamburger->setStatus(true);
    m_data.append(hamburger);
}

DishListModel::~DishListModel()
{

}

auto DishListModel::data() -> QQmlListProperty<Models::DishModel>
{
    return QQmlListProperty<Models::DishModel>(
        this,
        &m_data,
        &DishListModel::appendData,
        &DishListModel::countData,
        &DishListModel::atData,
        &DishListModel::clearData
    );
}

auto DishListModel::add() -> void
{
    Models::DishModel* dishModel = new Models::DishModel(this);
    dishModel->setProperty("name", "...");
    dishModel->setProperty("iconUrl", "");
    dishModel->setProperty("description", "...");
    dishModel->setProperty("status", "false");
    m_data.append(dishModel);

    emit dataChanged();
}

auto DishListModel::appendData(QQmlListProperty<Models::DishModel>* list, Models::DishModel* value) -> void
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    data->append(value);
}

auto DishListModel::countData(QQmlListProperty<Models::DishModel>* list) -> qsizetype
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    return data->size();
}

auto DishListModel::atData(QQmlListProperty<Models::DishModel>* list, qsizetype index) -> Models::DishModel*
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    return data->at(index);
}

auto DishListModel::clearData(QQmlListProperty<Models::DishModel>* list) -> void
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    qDeleteAll(data->begin(), data->end());
    data->clear();
}

} // namespace ViewModels
