#include "QComboBoxModel.h"

namespace Models {

QComboBoxModel::QComboBoxModel(QObject* parent)
    : QAbstractListModel(parent)
{
    model = { { 1, "John",  QPixmap(":/res/businessman.png") },
              { 2, "Masha", QPixmap(":/res/man.png") },
              { 3, "Ben",   QPixmap(":/res/priest.png") },
              { 4, "Kent",  QPixmap(":/res/woman.png") }
            };
}

QComboBoxModel::~QComboBoxModel()
{

}

auto QComboBoxModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.count();
}

auto QComboBoxModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::DisplayRole:
        return model.at(index.row()).name;
    case Qt::DecorationRole:
        return model.at(index.row()).icon;
    case Qt::UserRole: // not use right now
        return model.at(index.row()).id;
    default:
        break;
    }

    return QVariant();
}

auto QComboBoxModel::getItemForIndex(int index) -> TestModel
{
    return model.at(index);
}

} // namespace Models
