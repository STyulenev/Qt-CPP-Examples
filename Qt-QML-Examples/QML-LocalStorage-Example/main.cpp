#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // for Core.Settings in main.qml
    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("org.somecompany.com");
    app.setApplicationName("Some Application");

    QQuickView view;
    qDebug() << "Local storage path: " << view.engine()->offlineStoragePath();

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
