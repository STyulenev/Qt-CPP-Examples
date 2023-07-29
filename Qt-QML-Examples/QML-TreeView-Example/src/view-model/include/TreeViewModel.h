#pragma once

#include <QAbstractItemModel>

#include "TreeModel.h"

namespace ViewModel {

class TreeViewModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeViewModel(QObject* parent = 0);
    virtual ~TreeViewModel();

    virtual auto index(int row, int column, const QModelIndex& parent = QModelIndex()) const -> QModelIndex override;
    virtual auto parent(const QModelIndex& child) const -> QModelIndex override;
    virtual auto rowCount(const QModelIndex& parent = QModelIndex()) const -> int override;
    virtual auto columnCount(const QModelIndex& parent = QModelIndex()) const -> int override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    auto indexById(const int id) const -> QModelIndex;

    QVector<Model::TreeModel> model;

};

} // namespace ViewModels
