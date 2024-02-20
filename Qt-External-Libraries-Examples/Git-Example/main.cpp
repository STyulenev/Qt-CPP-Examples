#include <QApplication>
#include <QDebug>

#include "git.h"
#include "version.h"
#include <toml.hpp>
#include <boost/container/vector.hpp>

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);

    /*
     * Простой пример работы с подмодулем toml
     * В build необходим файл example.toml:
     * ```
     * title = "an example toml file"
     * ```
    */
    const auto data  = toml::parse("example.toml");
    const auto title = toml::find<std::string>(data, "title");
    qDebug() << QString::fromStdString(title);

    /*
     * Простой пример работы с подмодулем boost::container
     */
    boost::container::vector<int> vector = { 1, 2, 3, 4 };

    foreach (const int element, vector) {
        qDebug() << element;
    }

    /*
     * Информация о последнем коммите
     */
    qDebug() << GIT_AUTHOR_NAME << GIT_AUTHOR_EMAIL << GIT_HEAD_SHA1;

    /*
     * Информация о версии
     */
    qDebug() << QString("Ver. %0").arg(PROJECT_VERSION);

    return app.exec();
}
