#include "TableViewModel.h"

namespace ViewModels {

struct TestModel {
    int     id;
    QString name;
    int     age;
    bool    status;
};

TableViewModel::TableViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    model = { { 1,  "John",    17, true  },
              { 2,  "Masha",   24, false },
              { 3,  "Ben",     43, false },
              { 4,  "David",   14, true  },
              { 5,  "Lius",    52, true  },
              { 6,  "Bernard", 21, false },
              { 45, "Ben",     33, false },
              { 67, "David",   36, true  }
            };
}

TableViewModel::~TableViewModel()
{

}

auto TableViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 4;
}

auto TableViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).name;
        case 2: return model.at(index.row()).age;
        case 3: return model.at(index.row()).status;
        [[unlikely]] default: assert(!"Should not get here");
        }
    default:
        break;
    }

    return QVariant();
}

auto TableViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "name";
            case 2: return "age";
            case 3: return "status";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role) -> bool
{
    if (section == 3 && role == Qt::UserRole && orientation == Qt::Horizontal) {
        bool newStatus = value.toBool();

        this->beginResetModel();
        for (int i = 0; i < model.length(); i++) {
            model[i].status = newStatus;
        }
        this->endResetModel();
    }

    return true;
}

} // namespace ViewModels
