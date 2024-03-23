#include "Worker.h"

#include <QThread>
#include <QTimer>

namespace Controllers {

Worker::Worker(QObject* parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, &QTimer::timeout, this, &Worker::run);
    connect(this, &Worker::start, this, [this]() -> void {
        timer->start();
    });

    connect(this, &Worker::stop, this, [this]() -> void {
        timer->stop();
    });
}

Worker::~Worker()
{

}

auto Worker::run() -> void
{
    static int count = 1;
    emit data(count);
    count++;
}

} // namespace Controllers
