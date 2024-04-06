#include "ClipboardController.h"
#include <QDebug>

namespace Controllers {

ClipboardController::ClipboardController(QObject* parent) :
    QObject(parent)
{

}

ClipboardController::~ClipboardController()
{

}

auto ClipboardController::getLastClipboard() -> QString
{
    if (stack.empty())
        return "";
    else {
        return stack.pop();
    }
}

auto ClipboardController::addNewClipboard(const QString& text) -> void
{
    if (!text.isEmpty())
        stack.push(text);
}

auto ClipboardController::clear() -> void
{
    stack.clear();
}

auto ClipboardController::print() -> void
{
    foreach (const QString& line, stack) {
        qDebug() << line;
    }
}

} // namespace Controllers
