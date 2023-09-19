#pragma once

#include "Originator.h"

#include <QVector>

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

    auto save() -> void;
    auto previous() -> bool;
    auto next() -> bool;
    auto getStatus() -> std::pair<bool, bool>;
    auto showHistory() const -> void;

};

} // namespace Settings
