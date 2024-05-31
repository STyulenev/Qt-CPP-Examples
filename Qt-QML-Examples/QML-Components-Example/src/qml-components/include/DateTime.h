#pragma once

#include <QDateTime>
#include <QtQml/qqmlregistration.h>

class QTimer;

namespace Components {

class DateTime : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ getTime NOTIFY dateTimeChanged)
    Q_PROPERTY(QString date READ getDate NOTIFY dateTimeChanged)
    QML_ELEMENT

public:
    explicit DateTime(QObject* parent = nullptr);
    ~DateTime();

    auto getTime() const -> const QString&;
    auto getDate() const -> const QString&;

private slots:
    auto timeOut() -> void;

signals:
    auto dateTimeChanged() -> void;

private:
    QString m_time;
    QString m_date;
    QTimer* m_timer;

};

} // namespase Components
