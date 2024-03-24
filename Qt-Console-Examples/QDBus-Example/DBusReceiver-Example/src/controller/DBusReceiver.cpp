#include "DBusReceiver.h"

#include <QDebug>

namespace Controller {

DBusReceiver::DBusReceiver(QObject* parent) :
    QObject(parent)
{
    if (!QDBusConnection::sessionBus().isConnected()) {
        qDebug("Cannot connect to the D-Bus");
        throw;
    }

    dbusMessage = new org::Message("org.example.message", "/Message", QDBusConnection::sessionBus(), this);

    connect(dbusMessage, &OrgMessageInterface::sendMessage, this, &DBusReceiver::getDataDBus);
}

DBusReceiver::~DBusReceiver()
{

}

void DBusReceiver::getDataDBus(const QString& sender, const QString& data)
{
    QString message =  QString("%1 %2").arg(sender).arg(data);
    emit newMessage(message);
}

} // namespace Controller
