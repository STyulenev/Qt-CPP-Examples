#include <QString>
#include <QTextStream>
#include <QDebug>

#include "FutureController.h"

int main() {
    QTextStream cin(stdin);
    Controller::FutureController* sender = new Controller::FutureController();
    QString text;

    if (!sender)
        return -1;

    for (;;) {
        qDebug().noquote() << "Enter a new message: ";

        text = cin.readLine();

        if (text == "quit") {
            break;
        } else {
            sender->example(text);
            //sender->example2(text);
        }
    }

    delete sender;

    return 0;
}
