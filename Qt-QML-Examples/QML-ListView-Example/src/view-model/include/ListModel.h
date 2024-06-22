#pragma once

#include <QAbstractListModel>

namespace ViewModels {

class ListModel : public QAbstractListModel
{

    Q_OBJECT

private:
    struct TestModel {
        QString name;
        QString iconUrl;
        QString description;
        bool status;
    };

    QList<TestModel> model;

public:
    explicit ListModel(QObject* parent = 0);
    ~ListModel() = default;

    enum Role {
        DescriptionRole = Qt::UserRole + 1,
        StatusRole
    };

    auto rowCount(const QModelIndex& parent) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
