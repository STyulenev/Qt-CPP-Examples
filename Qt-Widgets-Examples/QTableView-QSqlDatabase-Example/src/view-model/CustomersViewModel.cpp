#include "CustomersViewModel.h"

namespace Consts {
    const int COLUMN_COUNT = 5;
}

namespace ViewModels {

CustomersViewModel::CustomersViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    dao.selectCustomers(customers);
}

CustomersViewModel::~CustomersViewModel()
{

}

auto CustomersViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return Consts::COLUMN_COUNT;
}

auto CustomersViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return customers.length();
}

auto CustomersViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return customers.at(index.row()).getId();
        case 1: return customers.at(index.row()).getFirstName();
        case 2: return customers.at(index.row()).getLastName();
        case 3: return customers.at(index.row()).getEmail();
        case 4: return customers.at(index.row()).getAge();
        [[unlikely]] default: assert(!"Should not get here");
        }
    default:
        break;
    }

    return QVariant();
}

auto CustomersViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto CustomersViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "first name";
            case 2: return "last name";
            case 3: return "email";
            case 4: return "age";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

} // namespace ViewModels
