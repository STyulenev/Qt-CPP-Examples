#pragma once

#include <QAbstractTableModel>
#include "CustomerDAO.h"

namespace ViewModels {

class CustomersViewModel : public QAbstractTableModel
{

public:
    explicit CustomersViewModel(QObject* parent = 0);
    ~CustomersViewModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    DAO::CustomerDAO dao;
    QList<Entities::Customer> customers;

};

} // namespace ViewModels
