#pragma once

#include <QAbstractListModel>

namespace ViewModels {

class ListModel : public QAbstractListModel
{

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
    virtual ~ListModel() = default;

protected:
    enum Role {
        DescriptionRole = Qt::UserRole + 1,
        StatusRole
    };

    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
