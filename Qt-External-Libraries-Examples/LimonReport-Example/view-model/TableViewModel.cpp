#include <TableViewModel.h>

TableViewModel::TableViewModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1, "John",  "12345", true  },
              { 2, "Masha", "12345", false },
              { 3, "Ben",   "12345", false },
              { 4, "Dodik", "12345", true  }
            };
}

TableViewModel::~TableViewModel()
{

}

int TableViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const
{
    return 4;
}

int TableViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const
{
    return model.length();
}

QVariant TableViewModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).name;
        case 2: return model.at(index.row()).number;
        case 3: return model.at(index.row()).status;// ? Qt::Checked : Qt::Unchecked;
        //[[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

Qt::ItemFlags TableViewModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool TableViewModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole /*|| role == Qt::CheckStateRole*/) { /*Qt::CheckStateRole*/
        switch (index.column()) {
        case 0:
            model[index.row()].id = value.toInt();
        case 1:
            model[index.row()].name = value.toString();
        case 2:
            model[index.row()].number = value.toString();
            break;
        case 3:
            model[index.row()].status = value.toBool(); // (value.toInt() == Qt::Checked); //
            qDebug() << "123";
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}
