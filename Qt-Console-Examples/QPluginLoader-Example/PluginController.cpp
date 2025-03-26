#include "PluginController.h"

#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QQmlApplicationEngine>

#include "IPlugin.h"

PluginController::PluginController()
{
    // ...
}

PluginController::~PluginController()
{
    // ...
}

void PluginController::load()
{
    // Директория plugin, рядом с bin файлом
    QDir pluginsDir("./plugins");

    foreach (const QString& pluginName, pluginsDir.entryList(QDir::Files)) {
        qDebug() << "Found:" << pluginName;

        QPluginLoader loader(pluginsDir.absoluteFilePath(pluginName));
        if (loader.load()) {
            if (IPlugin* myPlugin = qobject_cast<IPlugin*>(loader.instance())) {

                qmlRegisterType(QUrl(myPlugin->getComponentPath()), "ui.components", 1, 0, "MyTest");

                qDebug() << pluginName << " data:\n" <<
                    "-" << myPlugin->getComponentPath() << "\n" <<
                    "-" << myPlugin->getSomeData();
            } else {
                qDebug() << "Error #1";
            }

            loader.unload();
        } else {
            qDebug() << "Failed to load: " <<loader.errorString();
        }

        qDebug() << "\n";
    }
}
