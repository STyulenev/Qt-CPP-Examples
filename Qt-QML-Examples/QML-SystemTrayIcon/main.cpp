#include <QApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}


/*#include <QApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQuickWidget>
#include <QSystemTrayIcon>
#include <QQmlContext>

// Объявляем пользовательский тип данных для работы с иконкой в QML
Q_DECLARE_METATYPE(QSystemTrayIcon::ActivationReason)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine; // Инициализируем Qml движок

    // Регистрируем QSystemTrayIcon в качестве типа объекта в Qml
    qmlRegisterType<QSystemTrayIcon>("QSystemTrayIcon", 1, 0, "QSystemTrayIcon");
    // Регистрируем в QML тип данных для работы с получаемыми данными при клике по иконке
    qRegisterMetaType<QSystemTrayIcon::ActivationReason>("ActivationReason");
    // Устанавливаем Иконку в контекст движка
    engine.rootContext()->setContextProperty("iconTray", QIcon(":/gallery_kit.svg"));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}*/
