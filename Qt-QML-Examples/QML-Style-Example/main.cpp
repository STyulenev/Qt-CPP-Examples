#include <QGuiApplication>
#include <QQmlApplicationEngine>

//#include <QQuickStyle>

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");
    engine.addImportPath("qrc:/qml/Styles");

    // или в qtquickcontrols2.conf
    //QQuickStyle::setStyle("CustomStyle");

    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
