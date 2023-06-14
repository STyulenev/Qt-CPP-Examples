#pragma once

#include <QObject>
#include <QTest>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject* parent = 0);

private slots:
    auto test_bench1() -> void;
    auto test_bench2() -> void;
    auto test_bench3() -> void;
    auto test_bench4() -> void;
};

