#include "TreeModel.h"

namespace Models {

TreeModel::TreeModel()
{

}

TreeModel::TreeModel(const int& id, const QString& name, const int& parentId) :
    id(id),
    name(name),
    parentId(parentId)
{

}

TreeModel::TreeModel(const int&& id, const QString&& name, const int&& parentId) :
    id(id),
    name(name),
    parentId(parentId)
{

}

TreeModel::~TreeModel()
{

}

auto TreeModel::getId() const -> int
{
    return id;
}

auto TreeModel::getName() const -> const QString&
{
    return name;
}

auto TreeModel::getParentId() const -> int
{
    return parentId;
}

auto TreeModel::setId(int id) -> void
{
    this->id = id;
}

auto TreeModel::setName(const QString& name) -> void
{
    this->name = name;
}

auto TreeModel::setParentId(int parentId) -> void
{
    this->parentId = parentId;
}

auto TreeModel::childIds(const QVector<TreeModel>& model, const int parentId) noexcept -> QVector<int>
{
    QVector<int> childrenId;

    for (const auto& node : model)
        if (node.parentId == parentId)
            childrenId.push_back(node.id);

    return childrenId;
}

auto TreeModel::recordById(const QVector<TreeModel>& model, const int id) -> const TreeModel&
{
    for (const auto& node : model)
        if (node.id == id)
            return node;

    throw std::out_of_range("QVector<TreeModel> model is out of range");
}

} // namespace Models
