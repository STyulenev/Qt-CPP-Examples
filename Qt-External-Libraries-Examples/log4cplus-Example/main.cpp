#include <QCoreApplication>

#include <Logger.h>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    std::locale::global(std::locale()); // используем системную локаль по умолчанию

    log4cplus::Initializer initializer;
    log4cplus::BasicConfigurator config;
    config.configure();

    // Установка логирования
    if (!Settings::Logger::instance()->initialization()) {
        return -1;
    }

    LOG_WARN("Warning");
    LOG_ERROR("Eror");
    LOG_INFO("Information");

    return app.exec();
}
