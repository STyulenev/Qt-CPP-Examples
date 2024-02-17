#pragma once

#include <QObject>
#include <QTimer>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject* parent = nullptr);
    ~Worker();

private slots:
    auto run() -> void;

signals:
    auto data(int value) -> void;

    auto start() -> void;
    auto stop() -> void;

private:
    QTimer* timer;

};
