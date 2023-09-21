#include "Originator.h"

namespace Settings {

Originator::Originator(const QString& m_name, const QString& m_surname, const QString& m_description) :
    m_name(m_name),
    m_surname(m_surname),
    m_description(m_description)
{

}

auto Originator::name() const -> const QString&
{
    return m_name;
}

auto Originator::surname() const -> const QString&
{
    return m_surname;
}

auto Originator::description() const -> const QString&
{
    return m_description;
}

auto Originator::setName(const QString& name) -> void
{
    m_name = name;
}

auto Originator::setSurname(const QString& surname) -> void
{
    m_surname = surname;
}

auto Originator::setDescription(const QString& description) -> void
{
    m_description = description;
}

auto Originator::save() -> std::shared_ptr<Snapshot>
{
    return std::make_shared<Snapshot>(m_name, m_surname, m_description);
}

auto Originator::restore(std::shared_ptr<Snapshot> snapshot) -> void
{
    m_name        = snapshot->name();
    m_surname     = snapshot->surname();
    m_description = snapshot->description();
}

} // namespace Settings
