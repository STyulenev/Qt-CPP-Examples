#include "DBusSender.h"

#include "message_adaptor.h"

namespace Controller {

DBusSender::DBusSender(QObject* parent) :
    QObject(parent)
{
    if (!QDBusConnection::sessionBus().isConnected()) {
        qDebug("Cannot connect to the D-Bus");
        throw;
    }

    new MessageAdaptor(this);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/Message", this);
    connection.registerService("org.example.message");
}

DBusSender::~DBusSender()
{

}

} // namespace Controller
