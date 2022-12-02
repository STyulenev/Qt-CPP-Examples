#include "TableViewModelForStyledDelegates.h"

namespace ViewModels {

struct TestModelStyled {
    int     line_0;
    QString line_1;
};

TableViewModelForStyledDelegates::TableViewModelForStyledDelegates(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 10, ":/res/china.png"          },
              { 20, ":/res/germany.png"        },
              { 30, ":/res/india.png"          },
              { 50, ":/res/russia.png"         },
              { 60, ":/res/spain.png"          },
              { 80, ":/res/united-kingdom.png" }
            };
}

TableViewModelForStyledDelegates::~TableViewModelForStyledDelegates()
{

}

int TableViewModelForStyledDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const
{
    return 2;
}

int TableViewModelForStyledDelegates::rowCount([[maybe_unused]] const QModelIndex& index) const
{
    return model.length();
}

QVariant TableViewModelForStyledDelegates::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).line_0;
        case 1: return model.at(index.row()).line_1;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

Qt::ItemFlags TableViewModelForStyledDelegates::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QVariant TableViewModelForStyledDelegates::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "Slider";
            case 1: return "Image";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

bool TableViewModelForStyledDelegates::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].line_0 = value.toInt();
            break;
        case 1:
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace ViewModels
