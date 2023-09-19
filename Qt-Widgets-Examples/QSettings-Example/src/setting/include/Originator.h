#pragma once

#include "Snapshot.h"

#include <memory>

namespace Settings {

/*!
 * \brief Класс-создатель для промежуточного сохранения изменений
 */
class Originator
{

    friend class Caretaker;

private:
    QString m_name;
    QString m_surname;
    QString m_description;

public:
    Originator() = delete;
    explicit Originator(const QString& name, const QString& surname, const QString& description);
    ~Originator() = default;

    const QString& name() const;
    const QString& surname() const;
    const QString& description() const;

    auto setName(const QString& name) -> void;
    auto setSurname(const QString& surname) -> void;
    auto setDescription(const QString& description) -> void;

private:
    auto save() -> std::shared_ptr<Snapshot>;
    auto restore(std::shared_ptr<Snapshot> snapshot) -> void;

};

} // namespace Settings
