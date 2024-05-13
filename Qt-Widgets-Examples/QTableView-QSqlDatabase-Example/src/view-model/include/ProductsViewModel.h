#pragma once

#include <QAbstractTableModel>
#include "ProductDAO.h"

namespace ViewModels {

class ProductsViewModel : public QAbstractTableModel
{

public:
    explicit ProductsViewModel(QObject* parent = 0);
    ~ProductsViewModel();

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private slots:
    auto updateProductList() -> void;

private:
    DAO::ProductDAO* dao;
    QList<Entities::Product> products;

};

} // namespace ViewModels
