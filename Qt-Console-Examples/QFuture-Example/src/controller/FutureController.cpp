#include "FutureController.h"

#include <QDebug>
#include <QPromise>

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

void FutureController::example2(const QString& text)
{
    QPromise<QString> promise;
    QFuture<QString> future = promise.future();

    QScopedPointer<QThread> thread(QThread::create([&text](QPromise<QString> promise) -> void {
        QThread::sleep(3);

        promise.start();

        promise.addResult(text);
        qDebug() << "from thread №" << QThread::currentThreadId();

        promise.finish();
    }, std::move(promise)));
    thread->start();

    // Some long calculations
    {
        for (int i = 0; i < 100; i++)
            qDebug() << i << "from thread №" << QThread::currentThreadId();
    }

    future.waitForFinished();  // waiting
    qDebug() << future.result() << "from thread №" << QThread::currentThreadId();
}

} // namespace Controller
