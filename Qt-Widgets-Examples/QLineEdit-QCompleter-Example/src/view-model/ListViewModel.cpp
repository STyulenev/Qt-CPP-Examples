#include <ListViewModel.h>

#include <QDebug>

namespace ViewModels {

ListViewModel::ListViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model << "hello";
}

ListViewModel::~ListViewModel()
{

}

auto ListViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto ListViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (index.row() < 0 || index.row() >= this->rowCount(index)) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignLeft;
    case Qt::EditRole:
    case Qt::DisplayRole:
        return model.at(index.row());
    case Qt::ToolTipRole:
        return model.at(index.row());
    }

    return QVariant();
}

auto ListViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable;
}

auto ListViewModel::addData(const QString& text) -> void
{
    if (text.isEmpty())
        return;

    int ind = model.size();
    beginInsertRows(QModelIndex(), ind, ind);
    model.append(text);
    endInsertRows();

    QModelIndex index = createIndex(ind, 0, static_cast<void*>(0));
    emit dataChanged(index, index);
}

} // namespace ViewModels
