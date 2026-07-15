#include <QCoreApplication>
#include <QDebug>

#include <cppcoro/task.hpp>
#include <cppcoro/coroutine.hpp>
#include <cppcoro/sync_wait.hpp>

cppcoro::task<int> test1()
{
    int num = 10;
    co_return num;
}

cppcoro::task<> awaitable()
{
    int result = co_await test1();
    qDebug() << "Result: " << result;

    co_return;
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    {
        auto result = cppcoro::sync_wait(test1());
        qDebug() << "Result: " << result;
    }

    {
        cppcoro::sync_wait(awaitable());
    }

    return app.exec();
}
