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

QQmlListProperty<Models::DishModel> DishListModel::data()
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

void DishListModel::add()
{
    Models::DishModel* dishModel = new Models::DishModel(this);
    dishModel->setProperty("name", "...");
    dishModel->setProperty("iconUrl", "");
    dishModel->setProperty("description", "...");
    dishModel->setProperty("status", "false");
    m_data.append(dishModel);

    emit dataChanged();
}

void DishListModel::appendData(QQmlListProperty<Models::DishModel>* list, Models::DishModel* value)
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    data->append(value);
}

qsizetype DishListModel::countData(QQmlListProperty<Models::DishModel>* list)
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    return data->size();
}

Models::DishModel* DishListModel::atData(QQmlListProperty<Models::DishModel>* list, qsizetype index)
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    return data->at(index);
}

void DishListModel::clearData(QQmlListProperty<Models::DishModel>* list)
{
    QList<Models::DishModel*>* data = static_cast<QList<Models::DishModel*>*>(list->data);
    qDeleteAll(data->begin(), data->end());
    data->clear();
}

} // namespace ViewModels
