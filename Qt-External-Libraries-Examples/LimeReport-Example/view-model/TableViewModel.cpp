#include <TableViewModel.h>

TableViewModel::TableViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    model = { { 1, "John",  "12345", true  },
              { 2, "Masha", "12345", false },
              { 3, "Ben",   "12345", false },
              { 4, "Klark", "12345", true  }
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
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).name;
        case 2: return model.at(index.row()).number;
        case 3: return model.at(index.row()).status;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

auto TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "name";
            case 2: return "number";
            case 3: return "status";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModel::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].id = value.toInt();
            break;
        case 1:
            model[index.row()].name = value.toString();
            break;
        case 2:
            model[index.row()].number = value.toString();
            break;
        case 3:
            model[index.row()].status = value.toBool();
            break;
        [[unlikely]] default: assert(!"Should not get here");
        }

        emit dataChanged(index,index);
    }

    return true;
}
