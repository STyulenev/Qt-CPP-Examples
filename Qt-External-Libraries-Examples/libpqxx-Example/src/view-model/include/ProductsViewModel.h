#pragma once

#include <QAbstractTableModel>
#include <ProductDAO.h>

namespace ViewModels {

class ProductsViewModel : public QAbstractTableModel
{
public:
    explicit ProductsViewModel(QObject* parent = 0);
    virtual ~ProductsViewModel();

    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    ProductDAO* productDAO;
    QList<Entities::Product> products;

};

} // namespace ViewModels
