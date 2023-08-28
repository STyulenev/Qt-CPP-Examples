#include "ApplicationSettings.h"

#include <QSettings>
#include <QCoreApplication>

namespace Settings {

ApplicationSettings* ApplicationSettings::self = 0;

QSettings settings("Qt-CPP-Examples", "QSetting-Example");

ApplicationSettings* ApplicationSettings::getSetting()
{
    if (!self) {
        self = new ApplicationSettings();
    }

    return self;
}

auto ApplicationSettings::setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void
{
    settings.beginGroup("mainWindow");
    settings.setValue("size", size);
    settings.setValue("state", state);
    settings.endGroup();
}

auto ApplicationSettings::getMainWindowsSetting() -> std::pair<QSize, QByteArray>
{
    settings.beginGroup("mainWindow");
    auto pair = std::make_pair<QSize, QByteArray>(settings.value("size").toSize(), settings.value("state").toByteArray());
    settings.endGroup();

    return pair;
}

auto ApplicationSettings::setFieldsData(const QString& name, const QString& surname, const QString& description) -> void
{
    settings.beginGroup("fieldsData");
    settings.setValue("name", name);
    settings.setValue("surname", surname);
    settings.setValue("description", description);
    settings.endGroup();
}

auto ApplicationSettings::getFieldsData(QString& name, QString& surname, QString& description) -> void
{
    settings.beginGroup("fieldsData");
    name        = settings.value("name").toString();
    surname     = settings.value("surname").toString();
    description = settings.value("description").toString();
    settings.endGroup();
}

} // namespace Settings
