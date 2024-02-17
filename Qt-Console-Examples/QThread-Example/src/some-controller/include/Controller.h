#pragma once

#include "Worker.h"

class QThread;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject* parent = nullptr);
    virtual ~Controller();

    auto getWorker() const -> Worker*;

private:
    QThread* controllerThread;
    Worker* worker;

};
