#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
