#include <QCoreApplication>
#include <QDebug>

#include <taskflow/taskflow.hpp>

auto test1() -> void;
auto test2() -> void;

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    test1();
    test2();

    return app.exec();
}

// Простой пример с выводом логов в консоль
auto test1() -> void
{
    qDebug() << "test1()\n";

    tf::Executor executor;
    tf::Taskflow taskflow;

    auto [A, B, C, D] = taskflow.emplace(
        []() { qDebug() << "TaskA"; },
        []() { qDebug() << "TaskB"; },
        []() { qDebug() << "TaskC"; },
        []() { qDebug() << "TaskD"; }
        );

    A.precede(B, C);
    D.succeed(B, C);

    executor.run(taskflow).wait();
}

// Пример суммирования
auto test2() -> void
{
    qDebug() << "\ntest2()\n";

    tf::Taskflow taskflow;

    std::vector<double> data1 {1.0, 2.0, 3.0};
    std::vector<double> data2 {4.0, 5.0, 6.0};

    double sum1 = 0.0;
    auto task1 = taskflow.emplace([&data1, &sum1]() mutable {
        sum1 = std::accumulate(data1.begin(), data1.end(), 0);
    });

    double sum2 = 0.0;
    auto task2 = taskflow.emplace([&data2, &sum2]() mutable {
        sum2 = std::accumulate(data2.begin(), data2.end(), 0);
    });

    double total_sum = 0.0;
    auto task3 = taskflow.emplace([&total_sum, &sum1, &sum2]() mutable {
        total_sum = sum1 + sum2;
    });

    task3.succeed(task1);
    task3.succeed(task2);

    tf::Executor executor;
    executor.run(taskflow).wait();

    qDebug() << "total_sum = " << total_sum;
}
