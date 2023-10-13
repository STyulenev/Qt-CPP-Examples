#include "ToleranceBarPlugin.h"
#include "ToleranceBar.h"

ToleranceBarPlugin::ToleranceBarPlugin(QObject* parent) :
    QObject(parent)
{
    initialized = false;
}

bool ToleranceBarPlugin::isContainer() const
{
    return false;
}

bool ToleranceBarPlugin::isInitialized() const
{
    return initialized;
}

QIcon ToleranceBarPlugin::icon() const
{
    return QIcon();
}

QString ToleranceBarPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           "    <widget class=\"ToleranceBar\" name=\"toleranceBar\">\n"
           "    <property name=\"geometry\">\n"
           "        <rect>\n"
           "            <x>0</x>\n"
           "            <y>0</y>\n"
           "            <width>100</width>\n"
           "            <height>40</height>\n"
           "        </rect>\n"
           "    </property>\n"
           "    </widget>\n"
           "</ui>\n";
}

QString ToleranceBarPlugin::group() const
{
    return QStringLiteral("Special Widgets");
}

QString ToleranceBarPlugin::includeFile() const
{
    return QStringLiteral("ToleranceBar.h");
}

QString ToleranceBarPlugin::name() const
{
    return QStringLiteral("ToleranceBar");
}

QString ToleranceBarPlugin::toolTip() const
{
    return "";
}

QString ToleranceBarPlugin::whatsThis() const
{
    return "";
}

QWidget* ToleranceBarPlugin::createWidget(QWidget* parent)
{
    return new ToleranceBar(parent);
}

void ToleranceBarPlugin::initialize(QDesignerFormEditorInterface* core)
{
    Q_UNUSED(core)

    if (initialized)
        return;

    this->initialized = true;
}
