#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "CircularGauge.h"

auto main(int argc, char* argv[]) -> int
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<CircularGauge>("CppComponents", 1, 0, "CircularGauge");

    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
#else
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
#endif

    return app.exec();
}
