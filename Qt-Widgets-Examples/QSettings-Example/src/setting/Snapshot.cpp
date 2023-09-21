#include "Snapshot.h"

namespace Settings {

Snapshot::Snapshot(const QString& name, const QString& surname, const QString& description) :
    m_name(name),
    m_surname(surname),
    m_description(description)
{

}

auto Snapshot::name() const -> const QString&
{
    return m_name;
}

auto Snapshot::surname() const -> const QString&
{
    return m_surname;
}

auto Snapshot::description() const -> const QString&
{
    return m_description;
}

} // namespace Settings
