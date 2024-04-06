#pragma once

#include <QTextEdit>

class QKeyEvent;
class QMimeData;

namespace Controllers {
    class ClipboardController;
}

namespace Widgets {

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit CustomTextEdit(QWidget* parent = nullptr);
    ~CustomTextEdit();

public slots:
    auto keyPressEvent(QKeyEvent* event) -> void;
    auto insertFromMimeData(const QMimeData* source) -> void;

private slots:
    auto onClipboardChanged() -> void;

private:
    Controllers::ClipboardController* clipboardController;

};

} // namespace Widgets
