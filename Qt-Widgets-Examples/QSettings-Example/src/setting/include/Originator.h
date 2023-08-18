#pragma once

#include "Snapshot.h"
#include <QDebug>

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
    explicit Originator(const QString& name, const QString& surname, const QString& description);
    ~Originator() = default;

    const QString& name() const;
    const QString& surname() const;
    const QString& description() const;

    void setName(const QString& name);
    void setSurname(const QString& surname);
    void setDescription(const QString& description);

private:
    std::shared_ptr<Snapshot> save();
    void restore(std::shared_ptr<Snapshot> snapshot);

};

} // namespace Settings
