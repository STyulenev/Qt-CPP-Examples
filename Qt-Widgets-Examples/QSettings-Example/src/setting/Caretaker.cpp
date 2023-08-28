#include "Caretaker.h"

namespace Settings {

Caretaker::Caretaker(Originator* originator) :
    m_originator(originator)
{

}

void Caretaker::save()
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

bool Caretaker::previous()
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

bool Caretaker::next()
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

std::pair<bool, bool> Caretaker::getStatus()
{
    return std::make_pair<bool, bool>(!(currentItem == 0 && m_snapshots.size() > 0), !(currentItem + 1 == m_snapshots.size()));
}

void Caretaker::showHistory() const
{
    for (const std::shared_ptr<Snapshot>& snapshot : m_snapshots) {
        qDebug() << snapshot->name() << snapshot->surname() << snapshot->description();
    }
}

} // namespace Settings
