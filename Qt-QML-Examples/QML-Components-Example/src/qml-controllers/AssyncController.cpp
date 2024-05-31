#include "AssyncController.h"

#include <QDebug>
#include <QtConcurrent>

namespace Controllers {

AssyncController::AssyncController(QObject* parent) :
    QObject(parent)
{


}

AssyncController::~AssyncController()
{

}

AssyncController* AssyncController::run(const QJSValue& callback)
{
    auto future = QtConcurrent::run([this, callback]() -> void {
        //QThread::sleep(3);
        qDebug() <<  "from thread №" << QThread::currentThreadId();
        callback.call();
    });

    return this;
}

} // namespace Controllers
