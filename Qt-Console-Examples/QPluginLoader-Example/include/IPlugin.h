#pragma once

#include <QString>
#include <QVariant>

#include <QtPlugin>

// Общий интерфейс для приложения и плагинов
class IPlugin {
public:
    virtual ~IPlugin() { }

    virtual QString getComponentPath() const = 0;
    virtual QVariant getSomeData() const = 0;
};

Q_DECLARE_INTERFACE(IPlugin, "example.IPlugin/1.0")
