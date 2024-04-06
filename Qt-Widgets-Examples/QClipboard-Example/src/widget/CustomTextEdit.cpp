#include "CustomTextEdit.h"

#include <QApplication>
#include <QClipboard>
#include <QDebug>
#include <QKeyEvent>
#include <QMimeData>

#include "ClipboardController.h"

namespace Widgets {

CustomTextEdit::CustomTextEdit(QWidget* parent) :
    QTextEdit(parent)
{
    clipboardController = new Controllers::ClipboardController(this);

    if (QClipboard* clipboard = QApplication::clipboard()) {
        clipboard->setText("");
        connect(clipboard, &QClipboard::dataChanged, this, &CustomTextEdit::onClipboardChanged);
    }
}

CustomTextEdit::~CustomTextEdit()
{

}

auto CustomTextEdit::keyPressEvent(QKeyEvent* event) -> void
{
    if (event->modifiers().testFlag(Qt::ControlModifier)) {
        switch (event->key()) {
        case Qt::Key_X:
        case Qt::Key_C:
            // Сохранение текста в стек
            if (QClipboard* clipboard = QApplication::clipboard()) {
                if (const QMimeData* mimeData = clipboard->mimeData()) {
                    if (mimeData->hasText()) {
                        clipboardController->addNewClipboard(mimeData->text());
                    }
                }
            }
            break;
        case Qt::Key_V:

            // ...
            break;
        default:
            break;
        }
    }

    QTextEdit::keyPressEvent(event);
}

auto CustomTextEdit::insertFromMimeData(const QMimeData* source) -> void
{
    QTextEdit::insertPlainText(source->text());

    if (QClipboard* clipboard = QApplication::clipboard()) {
        clipboard->setText(clipboardController->getLastClipboard());
    }
}

auto CustomTextEdit::onClipboardChanged() -> void
{
    if (QClipboard* clipboard = QApplication::clipboard()) {
        if (const QMimeData* mimeData = clipboard->mimeData()) {
            if (mimeData->hasText()) {
                qDebug() << "clipboard has:" << mimeData->text() << "right now";
            }
        }
    }
}

} // namespace Widgets
