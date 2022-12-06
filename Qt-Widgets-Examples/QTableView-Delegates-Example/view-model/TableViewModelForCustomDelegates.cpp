#include "TableViewModelForCustomDelegates.h"

namespace ViewModels {

struct TestModelCustom {
    bool line_0;
};

TableViewModelForCustomDelegates::TableViewModelForCustomDelegates(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { true  },
              { false },
              { true  },
              { true  },
              { false },
              { false }
            };
}

TableViewModelForCustomDelegates::~TableViewModelForCustomDelegates()
{

}

auto TableViewModelForCustomDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 1;
}

auto TableViewModelForCustomDelegates::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableViewModelForCustomDelegates::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).line_0;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableViewModelForCustomDelegates::flags(const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable;
}

auto TableViewModelForCustomDelegates::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "RadioButton";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModelForCustomDelegates::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].line_0 = value.toInt();
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace ViewModels
