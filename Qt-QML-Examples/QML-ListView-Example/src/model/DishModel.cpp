#include "DishModel.h"

namespace Models {

DishModel::DishModel(QObject* parent) :
    QObject(parent)
{

}

DishModel::~DishModel()
{

}

auto DishModel::getName() const -> const QString&
{
    return m_name;
}

auto DishModel::getIconUrl() const -> const QString&
{
    return m_iconUrl;
}

auto DishModel::getDescription() const -> const QString&
{
    return m_description;
}

auto DishModel::getStatus() const -> bool
{
    return m_status;
}

auto DishModel::setName(const QString& name) -> void
{
    if (m_name == name)
        return;

    m_name = name;

    emit nameChanged();
}

auto DishModel::setIconUrl(const QString& iconUrl) -> void
{
    if (m_iconUrl == iconUrl)
        return;

    m_iconUrl = iconUrl;

    emit iconUrlChanged();
}

auto DishModel::setDescription(const QString& description) -> void
{
    if (m_description == description)
        return;

    m_description = description;

    emit descriptionChanged();
}

auto DishModel::setStatus(bool status) -> void
{
    if (m_status == status)
        return;

    m_status = status;

    emit statusChanged();
}

} // namespace Models
