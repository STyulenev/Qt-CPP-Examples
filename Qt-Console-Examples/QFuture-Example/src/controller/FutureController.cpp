#include "FutureController.h"

#include <QDebug>
#include <QtConcurrent>

namespace Controller {

FutureController::FutureController(QObject* parent) :
    QObject(parent)
{

}

FutureController::~FutureController()
{

}

void FutureController::example(const QString& text)
{
    auto future = QtConcurrent::run([this, &text]() -> void {
        QThread::sleep(3);
        qDebug() << text << "from thread №" << QThread::currentThreadId();
    });
}

} // namespace Controller
