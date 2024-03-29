#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "TreeViewModel.h"

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    // Register C ++ type to QML
    qmlRegisterType<ViewModel::TreeViewModel>("ViewModel", 0, 1, "TreeViewModel");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");

    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
