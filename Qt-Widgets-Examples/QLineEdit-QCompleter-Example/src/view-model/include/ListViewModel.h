#pragma once

#include <QAbstractListModel>

namespace ViewModels {

class ListViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ListViewModel(QObject* parent = 0);
    virtual ~ListViewModel();

    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;

    auto addData(const QString& text) -> void;

private:
    QVector<QString> model;

};

} // namespace ViewModels

