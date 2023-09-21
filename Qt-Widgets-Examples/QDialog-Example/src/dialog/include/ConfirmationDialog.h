#pragma once

#include "DialogData.h"

namespace Ui {
    class ConfirmationDialog;
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

    auto setIcon(const IconType&& iconType) -> void;
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
