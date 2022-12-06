#pragma once

#include <QSortFilterProxyModel>

namespace ProxyModels {

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProxyModel(QObject* parent = 0);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    enum Status {
        ALL = 0,
        TRUE,
        FALSE
    };

public slots:
    void setMinId(int minId);
    void setMaxId(int maxId);
    void setName(const QString& name);
    void setStatus(const Status status);

private:
    int     m_minId;
    int     m_maxId;
    QString m_name;
    Status  m_status;

};

} // namespace ProxyModels
