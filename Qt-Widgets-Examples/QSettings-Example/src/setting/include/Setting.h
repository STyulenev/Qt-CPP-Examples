#pragma once

#include <QSize>
#include <QByteArray>

class Setting
{
private:
    static Setting* self;

    Setting() {}
    Setting(const Setting&);
    Setting& operator=(Setting&);

public:
    static Setting* getSetting();

    auto setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void;
    auto getMainWindowsSetting() -> std::pair<QSize, QByteArray>;

    auto setFieldsData(const QString& name, const QString& surname, const QString& description) -> void;
    auto getFieldsData(QString& name, QString& surname, QString& description) -> void;
};
