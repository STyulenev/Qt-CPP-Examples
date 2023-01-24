#include "TableModel.h"

namespace ViewModels {

struct TestModel {
    int id;
    QString name;
    QString number;
    QString status;
};

TableModel::TableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1, "John",  "12345", "yes" },
              { 2, "Masha", "12346", "no"  },
              { 3, "Ben",   "12347", "yes" },
              { 4, "Alla",  "12348", "no"  }
            };

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
        case 3: return model.at(index.row()).status;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableModel::flags(const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
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

auto TableModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "DisplayRole";
    return roles;
}

auto TableModel::horizontalHeaders() const -> const QStringList&
{
    return horizontalHeaderList;
}

auto TableModel::columnWidths() const -> const QList<double>&
{
    return columnWidthList;
}

auto TableModel::textAlignments() const -> const QList<int>&
{
    return textAlignmentList;
}

} // namespace ViewModels
