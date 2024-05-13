#pragma once

#include <QAbstractItemModel>

#include "TreeModel.h"

namespace ViewModels {

class TreeViewModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeViewModel(QObject* parent = 0);
    ~TreeViewModel();

    auto index(int row, int column, const QModelIndex& parent = QModelIndex()) const -> QModelIndex override;
    auto parent(const QModelIndex& child) const -> QModelIndex override;
    auto rowCount(const QModelIndex& parent = QModelIndex()) const -> int override;
    auto columnCount(const QModelIndex& parent = QModelIndex()) const -> int override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    auto indexById(const int id) const -> QModelIndex;

private:
    QVector<Models::TreeModel> model;

};

} // namespace ViewModels
