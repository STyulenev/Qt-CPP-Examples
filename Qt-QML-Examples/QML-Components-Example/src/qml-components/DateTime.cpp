#include "DateTime.h"

#include <QTimer>

DateTime::DateTime(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);

    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &DateTime::timeOut);
    m_timer->start();
}

DateTime::~DateTime()
{
    m_timer->stop();
}

auto DateTime::getTime() const -> const QString&
{
    return this->m_time;
}

auto DateTime::getDate() const -> const QString&
{
    return this->m_date;
}

auto DateTime::timeOut() -> void
{
    const QDateTime dateTime = QDateTime::currentDateTime();

    m_time = dateTime.time().toString("hh:mm:ss");
    m_date = dateTime.date().toString("dddd, d MMMM yy");

    emit dateTimeChanged();
}
