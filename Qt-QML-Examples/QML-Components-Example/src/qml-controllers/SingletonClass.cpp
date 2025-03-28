#include "singletonclass.h"

#include <QTimer>

namespace Controllers {

SingletonClass* SingletonClass::self = 0;

SingletonClass::SingletonClass(QObject *parent) : QObject(parent)
{

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() -> void {
        emit newMessage("some message");
    });
    timer->setInterval(2000);
    timer->start();

}

SingletonClass* SingletonClass::instance()
{
    if (!self) {
        self = new SingletonClass();
    }

    return self;
}

QString SingletonClass::getMessage(SingletonClass::Message message)
{
    switch (message)
    {
        case Message::Info:
            return "This is Info Message";
        case Message::Debug:
            return "This is Debug Message";
        case Message::Warning:
            return "This is Warning Message";
        case Message::Error:
            return "This is Error Message";
        default:
            return "Nothin not found";
    }
}

} // namespace Controllers
