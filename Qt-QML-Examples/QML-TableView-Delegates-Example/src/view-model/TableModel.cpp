#include "TableModel.h"

#include <QUrl>

namespace ViewModels {

TableModel::TableModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    m_model = {
                { "John",  "qrc:/res/images/user1.png", "12345", true  },
                { "Masha", "qrc:/res/images/user2.png", "12345", false },
                { "Ben",   "qrc:/res/images/user3.png", "12345", false },
                { "Kent",  "qrc:/res/images/user4.png", "12345", true  }
              };

    m_columnWidthList = { 0.25, 0.25, 0.25, 0.25 };
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
    switch (role) {
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return m_model.at(index.row()).name;
        case 1: return QVariant("");
        case 2: return m_model.at(index.row()).number;
        case 3: return QVariant("");
        [[unlikely]] default: assert(!"Should not get here");
        }
    case Qt::CheckStateRole:
        switch (index.column()) {
        case 0: return QVariant();
        case 1: return QVariant();
        case 2: return QVariant();
        case 3: return m_model.at(index.row()).status ? Qt::Checked : Qt::Unchecked;
        [[unlikely]] default: assert(!"Should not get here");
        }
    case Qt::TextAlignmentRole:
        return Qt::AlignHCenter;
    case Qt::DecorationRole:
        switch (index.column()) {
        case 0: return QUrl();
        case 1: return QUrl(m_model.at(index.row()).iconUrl);
        case 2: return QUrl();
        case 3: return QUrl();
        [[unlikely]] default: assert(!"Should not get here");
        }
    case Qt::ToolTipRole:
        switch (index.column()) {
        case 0: return "User name here";
        case 1: return "User icon here";
        case 2: return "User number here\nYou can change it";
        case 3: return "User status here\nYou can change it";
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableModel::flags(const QModelIndex& index) const -> Qt::ItemFlags
{
    switch (index.column()) {
    case 0: return Qt::ItemIsEnabled;
    case 1: return Qt::ItemIsEnabled;
    case 2: return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    case 3: return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable;
    }

    return Qt::NoItemFlags;
}

auto TableModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "name";
            case 1: return "icon";
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
    switch (role) {
    case Qt::CheckStateRole:
        if (index.column() == 3) {
            m_model[index.row()].status = (value.toInt() == Qt::Checked);
        }
        emit dataChanged(index, index);
        break;
    case Qt::EditRole:
        if (index.column() == 2) {
            m_model[index.row()].number = value.toString();
        }

        emit dataChanged(index, index);
        break;
    }

    return true;
}

auto TableModel::roleNames() const -> QHash<int, QByteArray>
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole]       = "DisplayRole";
    roles[Qt::CheckStateRole]    = "CheckStateRole";
    roles[Qt::EditRole]          = "EditRole";
    roles[Qt::TextAlignmentRole] = "TextAlignmentRole";
    roles[Qt::DecorationRole]    = "DecorationRole";
    roles[Qt::ToolTipRole]       = "ToolTipRole";

    return roles;
}

auto TableModel::getColumnWidths() const -> const QList<double>&
{
    return m_columnWidthList;
}

} // namespace ViewModels
