#include "DishModel.h"

namespace Models {

DishModel::DishModel(QObject* parent) :
    QObject(parent)
{

}

DishModel::~DishModel()
{

}

QString DishModel::name() const
{
    return m_name;
}

QString DishModel::iconUrl() const
{
    return m_iconUrl;
}

QString DishModel::description() const
{
    return m_description;
}

bool DishModel::status() const
{
    return m_status;
}

void DishModel::setName(const QString &newName)
{
    m_name = newName;

    emit nameChanged();
}

void DishModel::setIconUrl(const QString &newIconUrl)
{
    m_iconUrl = newIconUrl;

    emit iconUrlChanged();
}

void DishModel::setDescription(const QString &newDescription)
{
    m_description = newDescription;

    emit descriptionChanged();
}

void DishModel::setStatus(bool newStatus)
{
    m_status = newStatus;

    emit statusChanged();
}

} // namespace Models
