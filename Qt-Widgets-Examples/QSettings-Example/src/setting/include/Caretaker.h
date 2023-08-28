#pragma once

#include "Originator.h"

namespace Settings {

/*!
 * \brief Класс-опекун для промежуточного сохранения изменений
 */
class Caretaker final
{
private:
    QVector<std::shared_ptr<Snapshot>> m_snapshots;
    Originator* m_originator;

    const short int maxLength = 10;
    int currentItem = 0;

public:
    Caretaker() = delete;
    explicit Caretaker(Originator* originator);
    ~Caretaker() = default;

    void save();
    bool previous();
    bool next();

    std::pair<bool, bool> getStatus();

    void showHistory() const;

};

} // namespace Settings
