#include "DBusReceiver.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    Controller::DBusReceiver* receiver = new Controller::DBusReceiver(&app);

    if (!receiver)
        return -1;

    QObject::connect(receiver, &Controller::DBusReceiver::newMessage, /*this,*/ [](const QString& message) -> void {
        qDebug() << message;
    });

    return app.exec();
}
