#include <QCoreApplication>

#include "Controller.h"
#include <QDebug>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    Controllers::Controller controller;

    QObject::connect(controller.getWorker(), &Controllers::Worker::data, /*this,*/ [](int value) -> void {
        qDebug() << QString::number(value);
    });

    emit controller.getWorker()->start();
    //emit controller.getWorker()->stop();

    return app.exec();
}
