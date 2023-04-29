#pragma once

#include <QAbstractTableModel>
#include "CustomerDAO.h"

namespace ViewModels {

class CustomersViewModel : public QAbstractTableModel
{
public:
    DAO::CustomerDAO dao;

private:
    QList<Entities::Customer> customers;

public:
    explicit CustomersViewModel(QObject* parent = 0);
    virtual ~CustomersViewModel();

    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

};

} // namespace ViewModels
