#pragma once

#include <QObject>
#include "message_interface.h"

namespace Controller {

class DBusReceiver : public QObject
{
    Q_OBJECT
public:
    explicit DBusReceiver(QObject* parent = nullptr);
    ~DBusReceiver();

public slots:
    void getDataDBus(const QString& sender, const QString& data);

signals:
    void newMessage(const QString& message);

private:
    org::Message* dbusMessage;

};

} // namespace Controller
