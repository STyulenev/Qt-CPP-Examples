#pragma once

#include <QSortFilterProxyModel>

namespace ProxyModels {

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProxyModel(QObject* parent = 0);
    auto filterAcceptsRow(int source_row, const QModelIndex& source_parent) const -> bool;
    auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant;

    enum Status {
        ALL = 0,
        TRUE,
        FALSE
    };

public slots:
    auto setMinId(int minId) -> void;
    auto setMaxId(int maxId) -> void;
    auto setName(const QString& name) -> void;
    auto setStatus(const Status status) -> void;

signals:
    auto dataReady(int count, int sumAge) -> void;

private:
    int     m_minId;
    int     m_maxId;
    QString m_name;
    Status  m_status;

};

} // namespace ProxyModels
