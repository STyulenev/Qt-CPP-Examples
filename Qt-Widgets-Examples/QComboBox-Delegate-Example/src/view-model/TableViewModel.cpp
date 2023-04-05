#include <TableViewModel.h>

namespace Models {

struct TestTableModel {
    int id;
    TestModel model;
};

TableViewModel::TableViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    model = { { 1, { 1, "John",  QPixmap(":/res/businessman.png") } },
              { 2, { 2, "Masha", QPixmap(":/res/man.png") } },
              { 3, { 3, "Ben",   QPixmap(":/res/priest.png") } },
              { 4, { 4, "Kent",  QPixmap(":/res/woman.png") } }
            };
}

TableViewModel::~TableViewModel()
{

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
    if (index.column() == 0) {
        switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return model.at(index.row()).id;
        case Qt::TextAlignmentRole:
            return QVariant(Qt::AlignVCenter | Qt::AlignHCenter);
        }
    }

    if (index.column() == 1) {
        switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return model.at(index.row()).model.name;
        case Qt::DecorationRole:
            return model.at(index.row()).model.icon;
        case Qt::UserRole:
            return model.at(index.row()).model.id;
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
            case 0: return "id";
            case 1: return "model";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModel::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].id = value.toInt();
            break;
        case 1:
            auto data = qvariant_cast<TestModel>(value);
            model[index.row()].model = data;
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace Models
