#pragma once

#include <QAbstractTableModel>

namespace ViewModels {

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    struct TestModel {
        int id;
        QString name;
        QString number;
        QString status;
    };

    QList<TestModel> m_model;

public:
    explicit TableModel(QObject* parent = 0);
    virtual ~TableModel() = default;

    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;
    virtual auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
