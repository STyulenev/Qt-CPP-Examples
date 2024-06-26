﻿#include "ProductsViewModel.h"

namespace Consts {
    const int COLUMN_COUNT = 6;
}

namespace ViewModels {

ProductsViewModel::ProductsViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    dao = new DAO::ProductDAO(this);

    connect(dao, &DAO::ProductDAO::productsTableChanged, this, &ProductsViewModel::updateProductList);

    updateProductList();
}

ProductsViewModel::~ProductsViewModel()
{

}

auto ProductsViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return Consts::COLUMN_COUNT;
}

auto ProductsViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return products.length();
}

auto ProductsViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return products.at(index.row()).getId();
        case 1: return products.at(index.row()).getType();
        case 2: return products.at(index.row()).getName();
        case 3: return products.at(index.row()).getManufacturer();
        case 4: return products.at(index.row()).getName();
        case 5: return products.at(index.row()).getPrice();
        [[unlikely]] default: assert(!"Should not get here");
        }
    default:
        break;
    }

    return QVariant();
}

auto ProductsViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto ProductsViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "type";
            case 2: return "name";
            case 3: return "manufacturer";
            case 4: return "count";
            case 5: return "price";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto ProductsViewModel::updateProductList() -> void
{
    QAbstractTableModel::beginResetModel();

    products.clear();
    dao->selectProducts(products);

    QAbstractTableModel::endResetModel();
}

} // namespace ViewModels
