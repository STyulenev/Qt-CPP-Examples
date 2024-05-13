#pragma once

#include <QSortFilterProxyModel>

namespace ProxyModels {

class ProxyTableViewModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    enum Status {
        ALL = 0,
        TRUE,
        FALSE
    };

    explicit ProxyTableViewModel(QObject* parent = 0);
    virtual ~ProxyTableViewModel() = default;

    auto filterAcceptsRow(int source_row, const QModelIndex& source_parent) const -> bool override;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    auto lessThan(const QModelIndex& sourceLeft, const QModelIndex& sourceRight) const -> bool override;

public slots:
    auto setMinId(int minId) -> void;
    auto setMaxId(int maxId) -> void;
    auto setName(const QString& name) -> void;
    auto setStatus(const Status& status) -> void;

signals:
    auto dataReady(int count, int sumAge) -> void;

private:
    int     m_minId;
    int     m_maxId;
    QString m_name;
    Status  m_status;

    mutable int count;
    mutable int sumAge;

};

} // namespace ProxyModels
