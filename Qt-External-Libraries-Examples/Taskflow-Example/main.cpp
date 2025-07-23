#include <QCoreApplication>

#include <taskflow/taskflow.hpp>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    tf::Executor executor;
    tf::Taskflow taskflow;

    auto [A, B, C, D] = taskflow.emplace(
        []() { std::cout << "TaskA\n"; },
        []() { std::cout << "TaskB\n"; },
        []() { std::cout << "TaskC\n"; },
        []() { std::cout << "TaskD\n"; }
        );

    A.precede(B, C);
    D.succeed(B, C);

    executor.run(taskflow).wait();

    return app.exec();
}
