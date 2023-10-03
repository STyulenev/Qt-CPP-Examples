#include "MyPlugins.h"

#include "ToleranceBarPlugin.h"
// ...

MyPlugins::MyPlugins(QObject* parent) :
    QObject(parent)
{
    widgets.append(new ToleranceBarPlugin(this));
    // ...
}

QList<QDesignerCustomWidgetInterface*> MyPlugins::customWidgets() const
{
    return widgets;
}
