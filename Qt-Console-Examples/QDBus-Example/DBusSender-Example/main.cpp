#include "DBusSender.h"

#include <QString>
#include <QTextStream>
#include <QDebug>

int main() {
    QTextStream cin(stdin);
    Controller::DBusSender* sender = new Controller::DBusSender();
    QString message;
    QString senderName = "Unknown";

    if (!sender)
        return -1;

    for (;;) {
        qDebug().noquote() << "Enter a new message: ";

        message = cin.readLine();

        if (message == "quit") {
            return 0;
        } else {
            emit sender->sendMessage(senderName, message);
            qDebug().noquote() << "Message" << message << "has sent";
        }
    }

    delete sender;

    return 0;
}
