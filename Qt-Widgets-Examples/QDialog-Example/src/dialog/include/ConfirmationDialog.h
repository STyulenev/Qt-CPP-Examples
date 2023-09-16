#pragma once

#include <QDialog>

namespace Ui {
    class ConfirmationDialog;
}

enum ExitCode {
    YES = 0,
    NO,
    CANCEL
};

enum DialogButtons {
    OK_BUTTON     = 0, // 1 << 0 == 001
    NO_BUTTON     = 1, // 1 << 1 == 010
    CANCEL_BUTTON = 2  // 1 << 2 == 100
};

inline DialogButtons operator|(const DialogButtons& lhs, const DialogButtons& rhs)
{
    return static_cast<DialogButtons>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

inline DialogButtons operator&(const DialogButtons& lhs, const DialogButtons& rhs)
{
    return static_cast<DialogButtons>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

namespace Dialogs {

class ConfirmationDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::ConfirmationDialog* ui;
    ExitCode code = ExitCode::CANCEL;

public:
    explicit ConfirmationDialog(QWidget* parent = nullptr);
    virtual ~ConfirmationDialog();

    auto setTitle(const QString& title) -> void;
    auto setFlags(const DialogButtons&& flags) -> void;

public slots:
    virtual auto exec() -> int;

private slots:
    auto on_btnCancel_clicked() -> void;
    auto on_btnNo_clicked() -> void;
    auto on_btnYes_clicked() -> void;

};

} // namespace Dialogs
