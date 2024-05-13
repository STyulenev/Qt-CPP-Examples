#pragma once

#include <QAbstractListModel>

#include <TestModel.h>

namespace Models {

class QComboBoxModel : public QAbstractListModel
{

public:
    QComboBoxModel(QObject* parent = nullptr);
    ~QComboBoxModel();

    auto rowCount(const QModelIndex& index) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;

    auto getItemForIndex(int index) -> TestModel;

private:
    QVector<TestModel> model;

};

} // namespace Models
