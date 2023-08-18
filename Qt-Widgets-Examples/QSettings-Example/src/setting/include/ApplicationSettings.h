#pragma once

#include <QSize>
#include <QByteArray>

namespace Settings {

/*!
 * \brief Класс для сохранения настроек приложения в ini файл
 */
class ApplicationSettings
{

private:
    static ApplicationSettings* self;

    ApplicationSettings() = default;
    ~ApplicationSettings() = default;
    ApplicationSettings(const ApplicationSettings&);
    ApplicationSettings& operator=(ApplicationSettings&);

public:
    static ApplicationSettings* getSetting();

    auto setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void;
    auto getMainWindowsSetting() -> std::pair<QSize, QByteArray>;

    auto setFieldsData(const QString& name, const QString& surname, const QString& description) -> void;
    auto getFieldsData(QString& name, QString& surname, QString& description) -> void;

};

} // namespace Settings
