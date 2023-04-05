#include "TableViewModel.h"

namespace ViewModels {

TableViewModel::TableViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{

}

TableViewModel::TableViewModel(const QVector<TestModel>& model, QObject* parent) :
    QAbstractTableModel(parent),
    model(model)
{

}

TableViewModel::~TableViewModel()
{

}

auto TableViewModel::setDefaultData() -> void
{
    model = { { "John",    17 },
              { "Masha",   24 },
              { "Ben",     43 },
              { "David",   14 },
              { "Lius",    52 },
              { "Bernard", 21 },
              { "Ben",     33 },
              { "David",   36 }
            };
}

auto TableViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 2;
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
        case 0: return model.at(index.row()).name;
        case 1: return model.at(index.row()).age;
        default: assert(!"Should not get here");
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
            case 0: return "name";
            case 1: return "age";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section + 1;
        }
    }

    return QVariant();
}

} // namespace ViewModels
