#include "TableViewModelForStyledDelegates.h"

namespace ViewModels {

struct TestModelStyled {
    int     line_0;
    QString line_1;
    bool    line_2;
};

TableViewModelForStyledDelegates::TableViewModelForStyledDelegates(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 10, ":/res/china.png",          true  },
              { 20, ":/res/germany.png",        false },
              { 30, ":/res/india.png",          true  },
              { 50, ":/res/russia.png",         true  },
              { 60, ":/res/spain.png",          false },
              { 80, ":/res/united-kingdom.png", false }
            };
}

TableViewModelForStyledDelegates::~TableViewModelForStyledDelegates()
{

}

auto TableViewModelForStyledDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 3;
}

auto TableViewModelForStyledDelegates::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableViewModelForStyledDelegates::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).line_0;
        case 1: return model.at(index.row()).line_1;
        case 2 :return model.at(index.row()).line_2 ? Qt::Checked : Qt::Unchecked; //
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableViewModelForStyledDelegates::flags(const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable;
}

auto TableViewModelForStyledDelegates::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "Slider";
            case 1: return "Image";
            case 2: return "CheckBox";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModelForStyledDelegates::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].line_0 = value.toInt();
            break;
        case 1:
            break;
        case 2:
            model[index.row()].line_2 = value.toBool();
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace ViewModels
