#include "Setting.h"

#include <QSettings>
#include <QCoreApplication>

Setting* Setting::self = 0;

QSettings settings("Qt-CPP-Examples", "QSetting-Example");

Setting* Setting::getSetting()
{
    if (!self) {
        self = new Setting();
    }

    return self;
}

auto Setting::setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void
{
    settings.beginGroup("mainWindow");
    settings.setValue("size", size);
    settings.setValue("state", state);
    settings.endGroup();
}

auto Setting::getMainWindowsSetting() -> std::pair<QSize, QByteArray>
{
    settings.beginGroup("mainWindow");
    auto pair = std::make_pair<QSize, QByteArray>(settings.value("size").toSize(), settings.value("state").toByteArray());
    settings.endGroup();

    return pair;
}

auto Setting::setFieldsData(const QString& name, const QString& surname, const QString& description) -> void
{
    settings.beginGroup("fieldsData");
    settings.setValue("name", name);
    settings.setValue("surname", surname);
    settings.setValue("description", description);
    settings.endGroup();
}

auto Setting::getFieldsData(QString& name, QString& surname, QString& description) -> void
{
    settings.beginGroup("fieldsData");
    name        = settings.value("name").toString();
    surname     = settings.value("surname").toString();
    description = settings.value("description").toString();
    settings.endGroup();
}
