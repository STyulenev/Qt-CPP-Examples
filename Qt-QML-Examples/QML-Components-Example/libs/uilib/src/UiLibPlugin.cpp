#include "UiLibPlugin.h"

#include "ColorTypes.h"

#include <QUrl>
#include <QtQml/QtQml>

void UiLibPlugin::initializePlugin()
{
    // for CMake static lib
    Q_INIT_RESOURCE(uilib_resource);

    qmlRegisterUncreatableType<ColorTypes>("ui.components", 1, 0, "ColorTypes", "only enum");

    qmlRegisterType(QUrl("qrc:/qml/SomeComponent.qml"), "ui.components", 1, 0, "SomeComponent");

    // qmlRegisterSingletonType...
    // ...
}
