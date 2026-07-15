#include <QCoreApplication>
#include <QDebug>

#include <magic_enum/magic_enum.hpp>

void test()
{
    enum class HttpMethod
    {
        GET,
        POST,
        PUT,
        DELETE
    };

    {
        const auto method = magic_enum::enum_cast<HttpMethod>("POST");

        switch (method.value())
        {
        case HttpMethod::GET:
            qDebug() << "Call GET method";
            break;
        case HttpMethod::POST:
            qDebug() << "Call POST method";
            break;
        case HttpMethod::PUT:
            qDebug() << "Call PUT method";
            break;
        case HttpMethod::DELETE:
            qDebug() << "Call DELETE method";
            break;
        default:
            qDebug() << "Call UNKNOWN method";
            break;
        }
    }

    {
        const auto method = magic_enum::enum_cast<HttpMethod>("post");

        if (!method.has_value())
        {
            qDebug() << "ERROR: Call UNKNOWN method";
        }
    }
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    test();

    return 0;//app.exec();
}
