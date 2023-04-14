﻿#include "OrdersViewModel.h"

namespace ViewModels {

OrdersViewModel::OrdersViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{
    orders = DAO::getConnection()->getListOfOrders();
}

OrdersViewModel::~OrdersViewModel()
{

}

auto OrdersViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 11;
}

auto OrdersViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return orders.length();
}

auto OrdersViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::TextAlignmentRole )
        return Qt::AlignCenter;

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return orders.at(index.row())->id;
        case 1: return orders.at(index.row())->customer_id->firstName;
        case 2: return orders.at(index.row())->customer_id->lastName;
        case 3: return orders.at(index.row())->customer_id->email;
        case 4: return orders.at(index.row())->product_id->product_type;
        case 5: return orders.at(index.row())->product_id->product_name;
        case 6: return orders.at(index.row())->product_id->price;
        case 7: return orders.at(index.row())->quantity;
        case 8: return (orders.at(index.row())->quantity * orders.at(index.row())->product_id->price);
        case 9: return orders.at(index.row())->order_date;
        case 10: return orders.at(index.row())->order_time;
        default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto OrdersViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto OrdersViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "first name";
            case 2: return "last name";
            case 3: return "email";
            case 4: return "type";
            case 5: return "name";
            case 6: return "price";
            case 7: return "quantity";
            case 8: return "total";
            case 9: return "date";
            case 10: return "time";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

} // namespace ViewModels
