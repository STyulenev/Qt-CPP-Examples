#include "TableModel.h"

namespace ViewModels {

TableModel::TableModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    m_model = {
                { 1, "John",  "12345", "yes" },
                { 2, "Masha", "12346", "no"  },
                { 3, "Ben",   "12347", "yes" },
                { 4, "Alla",  "12348", "no"  }
              };
}

auto TableModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 4;
}

auto TableModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return m_model.length();
}

auto TableModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::DisplayRole || role == Qt::CheckStateRole) {
        switch (index.column()) {
        case 0: return m_model.at(index.row()).id;
        case 1: return m_model.at(index.row()).name;
        case 2: return m_model.at(index.row()).number;
        case 3: return m_model.at(index.row()).status;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto TableModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return tr("id");
            case 1: return tr("name");
            case 2: return tr("number");
            case 3: return tr("status");
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
    // other roles

    return roles;
}

} // namespace ViewModels
