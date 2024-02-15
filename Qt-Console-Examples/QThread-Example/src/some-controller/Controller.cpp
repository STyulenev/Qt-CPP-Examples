#include "Controller.h"

#include <QThread>

Controller::Controller(QObject* parent) :
    QObject(parent)
{
    controllerThread = new QThread();
    worker = new Worker();

    worker->moveToThread(controllerThread);
    controllerThread->start();
}

Controller::~Controller()
{
    emit worker->stop();

    controllerThread->quit();
    controllerThread->wait();

    delete controllerThread;
    controllerThread = nullptr;

    delete worker;
}

auto Controller::getWorker() const -> Worker*
{
    return worker;
}
