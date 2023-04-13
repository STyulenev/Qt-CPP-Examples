#include "CustomersViewModel.h"

namespace ViewModels {

CustomersViewModel::CustomersViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    customers = DAO::getConnection()->getListOfCustomers();
}

CustomersViewModel::~CustomersViewModel()
{

}

auto CustomersViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 5;
}

auto CustomersViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return customers.length();
}

auto CustomersViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::TextAlignmentRole )
        return Qt::AlignCenter;

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return customers.at(index.row())->id;
        case 1: return customers.at(index.row())->firstName;
        case 2: return customers.at(index.row())->lastName;
        case 3: return customers.at(index.row())->email;
        case 4: return customers.at(index.row())->age;
        default: assert(!"Should not get here");
        }
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
