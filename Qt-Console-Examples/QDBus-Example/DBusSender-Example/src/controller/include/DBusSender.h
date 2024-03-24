#pragma once

#include <QObject>
#include <QtDBus/QDBusConnection>

namespace Controller {

class DBusSender : public QObject
{
    Q_OBJECT
public:
    explicit DBusSender(QObject* parent = nullptr);
    ~DBusSender();

signals:
    void sendMessage(const QString& sender, const QString& data);

};

} // namespace Controller
