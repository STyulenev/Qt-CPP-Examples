#include "TableViewModel.h"

namespace ViewModels {

struct TestModel {
    int     id;
    QString name;
    QString number;
    bool    status;
};

TableViewModel::TableViewModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1,  "John",    "10000", true  },
              { 2,  "Masha",   "11000", false },
              { 3,  "Ben",     "12000", false },
              { 4,  "David",   "13000", true  },
              { 5,  "Lius",    "12300", true  },
              { 6,  "Bernard", "12340", false },
              { 45, "Ben",     "12345", false },
              { 67, "David",   "12346", true  }
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
    if (role == Qt::TextAlignmentRole )
        return Qt::AlignCenter;

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).name;
        case 2: return model.at(index.row()).number;
        case 3: return model.at(index.row()).status;
        default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableViewModel::flags(const QModelIndex& index) const -> Qt::ItemFlags
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

} // namespace ViewModels
