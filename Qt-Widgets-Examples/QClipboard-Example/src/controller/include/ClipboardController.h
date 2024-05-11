#pragma once

#include <QObject>
#include <QStack>

namespace Controllers {

class ClipboardController : public QObject
{
    Q_OBJECT

public:
    explicit ClipboardController(QObject* parent = nullptr);
    ~ClipboardController();

    auto getLastClipboard() -> QString;
    auto addNewClipboard(const QString& text) -> void;

    auto clear() -> void;
    auto print() -> void;

private:
    QStack<QString> stack;

};

} // namespace Controllers
