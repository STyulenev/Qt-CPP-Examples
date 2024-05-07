#pragma once

#include <QAbstractListModel>

namespace ViewModels {

struct TestModel;

class ListViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ListViewModel(QObject* parent = 0);
    virtual ~ListViewModel();

    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;

private:
    QVector<TestModel> model;

};

} // namespace ViewModels
