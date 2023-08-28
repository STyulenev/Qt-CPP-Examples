#include "Originator.h"

namespace Settings {

Originator::Originator(const QString& m_name, const QString& m_surname, const QString& m_description) :
    m_name(m_name),
    m_surname(m_surname),
    m_description(m_description)
{

}

const QString& Originator::name() const
{
    return m_name;
}

const QString& Originator::surname() const
{
    return m_surname;
}

const QString& Originator::description() const
{
    return m_description;
}

void Originator::setName(const QString& name)
{
    m_name = name;
}

void Originator::setSurname(const QString& surname)
{
    m_surname = surname;
}

void Originator::setDescription(const QString& description)
{
    m_description = description;
}

std::shared_ptr<Snapshot> Originator::save()
{
    return std::make_shared<Snapshot>(m_name, m_surname, m_description);
}

void Originator::restore(std::shared_ptr<Snapshot> snapshot)
{
    m_name        = snapshot->name();
    m_surname     = snapshot->surname();
    m_description = snapshot->description();
}

} // namespace Settings
