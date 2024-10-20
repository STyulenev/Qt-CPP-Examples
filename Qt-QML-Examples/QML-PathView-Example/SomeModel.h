#pragma once

#include <QAbstractListModel>
#include <QUrl>

namespace Models {

class TestModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QUrl    icon READ getIconUrl CONSTANT)

private:
    QString name;
    QString iconUrl;

public:
    TestModel(QObject *parent = 0) : QObject(parent) {}
    TestModel(QString name, QString iconUrl, QObject *parent = 0) : name(name), iconUrl(iconUrl), QObject(parent) {}

    const QString& getName() const { return name; }
    QUrl getIconUrl() const {
            return QUrl(iconUrl);
    }

};

} // namespace Models

Q_DECLARE_METATYPE(Models::TestModel *)

class SomeModel : public QAbstractListModel
{

    Q_OBJECT

private:
    QList<Models::TestModel*> model;

public:
    explicit SomeModel(QObject *parent = 0);
    ~SomeModel() = default;

    auto rowCount(const QModelIndex &parent) const -> int override;
    auto data(const QModelIndex &index, int role) const -> QVariant override;
    auto flags(const QModelIndex &index) const -> Qt::ItemFlags override;
    auto roleNames() const -> QHash<int, QByteArray> override;

};
