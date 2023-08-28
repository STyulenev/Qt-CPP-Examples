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

    const QString& name() const;
    const QString& surname() const;
    const QString& description() const;

};

} // namespace Settings
