#pragma once

#include <QAbstractTableModel>
#include "OrderDAO.h"

namespace ViewModels {

class OrdersViewModel : public QAbstractTableModel
{

public:
    explicit OrdersViewModel(QObject* parent = 0);
    ~OrdersViewModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    DAO::OrderDAO dao;
    QList<Entities::Order> orders;

};

} // namespace ViewModels
