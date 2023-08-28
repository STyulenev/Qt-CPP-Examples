#include "Snapshot.h"

namespace Settings {

Snapshot::Snapshot(const QString& name, const QString& surname, const QString& description) :
    m_name(name),
    m_surname(surname),
    m_description(description)
{

}

const QString& Snapshot::name() const
{
    return m_name;
}

const QString& Snapshot::surname() const
{
    return m_surname;
}

const QString& Snapshot::description() const
{
    return m_description;
}

} // namespace Settings
