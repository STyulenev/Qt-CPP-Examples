#include <QQmlApplicationEngine>
#include <QtQuickTest/quicktest.h>
#include <QObject>

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:
    auto qmlEngineAvailable(QQmlEngine* engine) -> void
    {
        engine->addImportPath(":/qml");

        // qmlRegisterType<...>("...", 1, 0, "...");
    }
};

QUICK_TEST_MAIN_WITH_SETUP(QMLTest, Setup)

#include "main.moc"
