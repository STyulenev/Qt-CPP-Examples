#include "ConcretePlugin.h"

MyPlugin::~MyPlugin()
{

}

QString MyPlugin::getComponentPath() const
{
    return "qrc:/MyTest.qml";
}

QVariant MyPlugin::getSomeData() const
{
    return QVariant("test data");
}
