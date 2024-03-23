#pragma once

#include "Worker.h"

class QThread;

namespace Controllers {

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject* parent = nullptr);
    ~Controller();

    auto getWorker() const -> Worker*;

private:
    QThread* controllerThread;
    Worker* worker;

};

} // namespace Controllers
