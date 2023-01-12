#include "TableViewModelForCustomDelegates.h"

#include <QColor>

namespace ViewModels {

struct TestModelCustom {
    bool       line_0;
    QByteArray line_1;
    QColor     line_2;
};

TableViewModelForCustomDelegates::TableViewModelForCustomDelegates(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { true,  QByteArray(), Qt::GlobalColor::red     },
              { false, QByteArray(), Qt::GlobalColor::green   },
              { true,  QByteArray(), Qt::GlobalColor::blue    },
              { true,  QByteArray(), Qt::GlobalColor::yellow  },
              { false, QByteArray(), Qt::GlobalColor::gray    },
              { false, QByteArray(), Qt::GlobalColor::magenta }
            };
}

TableViewModelForCustomDelegates::~TableViewModelForCustomDelegates()
{

}

auto TableViewModelForCustomDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 3;
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
        case 1: return model.at(index.row()).line_1;
        case 2: return model.at(index.row()).line_2.name();
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
            case 1: return "FileEdit";
            case 2: return "ColorEdit";
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
        case 1:
            model[index.row()].line_1 = value.toByteArray();
            break;
        case 2:
            model[index.row()].line_2 = QColor(value.toString());
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace ViewModels
