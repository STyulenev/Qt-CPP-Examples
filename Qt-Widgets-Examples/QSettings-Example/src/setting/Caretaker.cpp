#include "Caretaker.h"

#include <QDebug>

namespace Settings {

Caretaker::Caretaker(Originator* originator) :
    m_originator(originator)
{

}

auto Caretaker::save() -> void
{
    if (m_snapshots.size() == 0) {
        currentItem = 0;
        m_snapshots.push_back(m_originator->save());
    } else {
        // Если текущий элемент последний
        if (currentItem == m_snapshots.size() - 1) {
            if (m_snapshots.size() == maxLength) {
                m_snapshots.pop_front();
            } else {
                currentItem++;
            }

            m_snapshots.push_back(this->m_originator->save());

        } else { // Если текущий элемент не последний
            m_snapshots.resize(currentItem);
            m_snapshots.push_back(m_originator->save());
        }
    }
}

auto Caretaker::previous() -> bool
{
    if (m_snapshots.size() == 0 || currentItem == 0) {
        return false;
    } else {
        currentItem--;
        std::shared_ptr<Snapshot> Snapshot = m_snapshots.at(currentItem);

        try {
            m_originator->restore(Snapshot);
        } catch (...) {
            //this->previous();
        }

        return true;
    }
}

auto Caretaker::next() -> bool
{
    if (currentItem + 1 == m_snapshots.size()) {
        return false;
    } else {
        currentItem++;
        std::shared_ptr<Snapshot> Snapshot = m_snapshots.at(currentItem);

        try {
            m_originator->restore(Snapshot);
        } catch (...) {
            //this->previous();
        }

        return true;
    }
}

auto Caretaker::getStatus() -> std::pair<bool, bool>
{
    return std::make_pair<bool, bool>(!(currentItem == 0 && m_snapshots.size() > 0), !(currentItem + 1 == m_snapshots.size()));
}

auto Caretaker::showHistory() const -> void
{
    for (const std::shared_ptr<Snapshot>& snapshot : m_snapshots) {
        qDebug() << snapshot->name() << snapshot->surname() << snapshot->description();
    }
}

} // namespace Settings
