#pragma once

#include <IPlugin.h>

class MyPlugin : public QObject, public IPlugin
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_PLUGIN_METADATA(IID "exampe.IPlugin")

public:
    ~MyPlugin();

    QString getComponentPath() const;
    QVariant getSomeData() const;
};
