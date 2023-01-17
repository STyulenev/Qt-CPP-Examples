#include "TableModel.h"

namespace ViewModels {

struct TestModel {
    int id;
    QString name;
    QString number;
    bool status;
};

TableModel::TableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1, "John",  "12345", true  },
              { 2, "Masha", "12345", false },
              { 3, "Ben",   "12345", false },
              { 4, "Dodik", "12345", true  }
            };

    horizontalHeaderList << "id" << "name" << "number" << "status";

    horizontalHeaderList = QStringList({ tr("id"), tr("name"), tr("number"), tr("status") });
    textAlignmentList = { Qt::AlignCenter, Qt::AlignCenter, Qt::AlignCenter, Qt::AlignCenter };
    columnWidthList = { 0.1, 0.35, 0.35, 0.2 };
}

TableModel::~TableModel()
{

}

auto TableModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 4;
}

auto TableModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::DisplayRole || role == Qt::CheckStateRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).name;
        case 2: return model.at(index.row()).number;
        case 3: return model.at(index.row()).status ? Qt::Checked : Qt::Unchecked;
            //[[unlikely]] default: assert(!"Should not get here");
        }
    }


    /*if (role == Qt::DecorationRole) {
        return QColor(Qt::blue);
    }

    if (role == Qt::ToolTipRole || role == Qt::WhatsThisRole) {
        switch (index.column()) {
        case 0: return "id";
        case 1: return "name";
        case 2: return "number";
        case 3: return "status";
        }
    }

    if (role == Qt::TextAlignmentRole) {
        return Qt::AlignCenter;
    }

    if (role == Qt::BackgroundRole && index.column() == 0) {
        return QColor(Qt::yellow);
    }*/


    return QVariant();
}

auto TableModel::flags(const QModelIndex& index) const -> Qt::ItemFlags
{
    switch (index.column()) {
    case 0: return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    case 1: return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    case 2: return Qt::ItemIsEnabled | Qt::ItemIsSelectable;// | Qt::ItemIsEditable;
    case 3: return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable;
    }

    return Qt::NoItemFlags; // QAbstractTableModel::flags(index);//
}

auto TableModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
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

auto TableModel::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::CheckStateRole) {
        if (index.column() == 3) {
            qDebug() << "123" << value.toInt();
            model[index.row()].status = (value.toInt() == Qt::Checked);
        }
        emit dataChanged(index, index);
    }

    /*if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].id = value.toInt();
        case 1:
            model[index.row()].name = value.toString();
        case 2:
            model[index.row()].number = value.toString();
            break;
        }

        emit dataChanged(index,index);
    }*/

    return true;
}

auto TableModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "DisplayRole";
    roles[Qt::CheckStateRole] = "CheckStateRole";
    return roles;
}

} // namespace ViewModels
