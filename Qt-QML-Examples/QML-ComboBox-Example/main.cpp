#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ComboBoxViews.h"

auto main(int argc, char* argv[]) -> int
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // Register C ++ type to QML
    qmlRegisterType<Views::ComboBoxViews>("ViewModels", 0, 1, "ComboBoxViews");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
