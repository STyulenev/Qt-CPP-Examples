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

    virtual ~LinearGraphicViewModel() = default;

protected:
    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;

};

} // namespace ViewModels
