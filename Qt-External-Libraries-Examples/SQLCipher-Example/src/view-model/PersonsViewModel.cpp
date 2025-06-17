#include "PersonsViewModel.h"

namespace ViewModels {

PersonsViewModel::PersonsViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    dao = new DAO::PersonDAO();

    //dao->init();
    //dao->openDatabase();
    dao->selectPeople(people);
}

PersonsViewModel::~PersonsViewModel()
{
    //dao->closeDatabase();
    delete dao;
}

auto PersonsViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 4;
}

auto PersonsViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return people.length();
}

auto PersonsViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return people.at(index.row()).getId();
        case 1: return people.at(index.row()).getFirstName();
        case 2: return people.at(index.row()).getLastName();
        case 3: return people.at(index.row()).getAge();
        default: assert(!"Should not get here");
        }
    default:
        break;
    }

    return QVariant();
}

auto PersonsViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto PersonsViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "first name";
            case 2: return "last name";
            case 3: return "age";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

} // namespace ViewModels
