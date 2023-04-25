#include "TreeViewModel.h"

#include <QBrush>

namespace ViewModel {

TreeViewModel::TreeViewModel(QObject* parent) :
    QAbstractItemModel(parent)
{
    model = {
        {  1, "Level 1",       0  },
        {  2, "Level 1.1",     1  },
        {  3, "Level 1.2",     1  },
        {  4, "Level 2",       0  },
        {  5, "Level 2.1",     4  },
        {  6, "Level 1.3",     1  },
        {  7, "Level 3",       0  },
        {  8, "Level 3.1",     7  },
        {  9, "Level 3.1.1",   8  },
        { 10, "Level 3.1.2",   8  },
        { 11, "Level 3.1.2.1", 10 },
    };
}

TreeViewModel::~TreeViewModel()
{

}

auto TreeViewModel::index(int row, int column, const QModelIndex& parent) const -> QModelIndex
{
    const int parentId = parent.isValid() ? parent.internalId() : 0;

    return createIndex(row, column, Model::TreeModel::childIds(model, parentId).at(row));
}

auto TreeViewModel::parent(const QModelIndex& child) const -> QModelIndex
{
    const int id = child.internalId();
    const int parentId = Model::TreeModel::recordById(model, id).getParentId();

    return indexById(parentId);
}

auto TreeViewModel::rowCount(const QModelIndex& parent) const -> int
{
    const int parentId = parent.isValid() ? parent.internalId() : 0;

    return Model::TreeModel::childIds(model, parentId).size();
}

auto TreeViewModel::columnCount([[maybe_unused]] const QModelIndex& parent) const -> int
{
    return 3;
}

auto TreeViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto TreeViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    const auto& node = Model::TreeModel::recordById(model, index.internalId());

    if (role == Qt::DisplayRole ) {
        switch (index.column()) {
        case 0: return node.getId();
        case 1: return node.getName();
        case 2: return node.getParentId();
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    if (role == Qt::BackgroundRole && node.getParentId() == 0) {
        QBrush background(Qt::yellow);
        return background;
    }

    return QVariant();
}

auto TreeViewModel::indexById(const int id) const -> QModelIndex
{
    if (id == 0) {
        return QModelIndex();
    } else {
        int parentId = Model::TreeModel::recordById(model, id).getParentId();
        int row = Model::TreeModel::childIds(model, parentId).indexOf(id);

        return index(row, 0, indexById(parentId));
    }
}

auto TreeViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "name";
            case 2: return "parent id";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

} // namespace ViewModels
