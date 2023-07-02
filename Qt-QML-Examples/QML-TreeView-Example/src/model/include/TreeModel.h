#pragma once

#include <QVector>

namespace Model {

class TreeModel
{
private:
    int id;
    QString name;
    int parentId;

public:
    TreeModel();
    TreeModel(const int& id, const QString& name, const int& parentId);
    TreeModel(const int&& id, const QString&& name, const int&& parentId);

    ~TreeModel();

    auto getId() const -> int;
    auto getName() const -> const QString&;
    auto getParentId() const -> int;

    auto setId(int newId) -> void;
    auto setName(const QString& newName) -> void;
    auto setParentId(int newParentId) -> void;

    static auto childIds(const QVector<TreeModel>& model, const int parentId) noexcept -> QVector<int>;
    static auto recordById(const QVector<TreeModel>& model, const int id) -> const TreeModel&;
};

} // namespace Model
