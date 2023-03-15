#pragma once

#include <QAbstractListModel>

namespace ViewModels {

struct TestModel;

class ListModel : public QAbstractListModel
{
public:
    explicit ListModel(QObject* parent = 0);
    virtual ~ListModel();

    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto roleNames() const -> QHash<int, QByteArray> override;

private:
    QList<TestModel> model;

protected:
    enum Role {
        WeightRole = Qt::UserRole + 1,
        PriceRole
    };

};

} // namespace ViewModels
