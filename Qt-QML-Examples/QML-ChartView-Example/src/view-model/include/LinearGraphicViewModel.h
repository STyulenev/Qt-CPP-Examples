#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

class LinearGraphicViewModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QVector<std::pair<double, double>> m_data;

public:
    LinearGraphicViewModel(QObject* parent = 0) = delete;
    explicit LinearGraphicViewModel(const QVector<std::pair<double, double>>& data, QObject* parent = 0);

    ~LinearGraphicViewModel() = default;

    auto columnCount(const QModelIndex& parent) const -> int override;
    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;

};

} // namespace ViewModels
