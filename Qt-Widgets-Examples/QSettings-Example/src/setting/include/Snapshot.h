#pragma once

#include <QString>

namespace Settings {

/*!
 * \brief Класс-снимок для промежуточного сохранения изменений
 */
class Snapshot
{
private:
    QString m_name;
    QString m_surname;
    QString m_description;

public:
    Snapshot() = delete;
    explicit Snapshot(const QString& name, const QString& surname, const QString& description);
    ~Snapshot() = default;

    auto name() const -> const QString&;
    auto surname() const -> const QString&;
    auto description() const -> const QString&;

};

} // namespace Settings
