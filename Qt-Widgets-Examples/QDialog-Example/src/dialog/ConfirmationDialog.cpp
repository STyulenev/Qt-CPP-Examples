#include "ConfirmationDialog.h"
#include "ui_ConfirmationDialog.h"

#include <QPixmap>

namespace Dialogs {

ConfirmationDialog::ConfirmationDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationDialog)
{
    ui->setupUi(this);
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete ui;
}

auto ConfirmationDialog::setIcon(const IconType&& iconType) -> void
{
    switch (iconType) {
    case IconType::ERROR:
        ui->iconLabel->setPixmap(QPixmap(":/res/icon/error.png"));
        break;
    case IconType::INFORMATION:
        ui->iconLabel->setPixmap(QPixmap(":/res/icon/information.png"));
        break;
    case IconType::NONE:
        ui->iconLabel->setPixmap(QPixmap());
        break;
    case IconType::WARNING:
        ui->iconLabel->setPixmap(QPixmap(":/res/icon/warning.png"));
        break;
    default:
        ui->iconLabel->setPixmap(QPixmap());
        break;
    }
}

auto ConfirmationDialog::setTitle(const QString& title) -> void
{
    ui->titleLabel->setText(title);
}

auto ConfirmationDialog::setFlags(const DialogButtons&& flags) -> void
{
    ui->btnYes->setHidden(!((flags & DialogButtons::OK_BUTTON) == DialogButtons::OK_BUTTON));
    ui->btnNo->setHidden(!((flags & DialogButtons::NO_BUTTON) == DialogButtons::NO_BUTTON));
    ui->btnCancel->setHidden(!((flags & DialogButtons::CANCEL_BUTTON) == DialogButtons::CANCEL_BUTTON));
}

auto ConfirmationDialog::exec() -> int
{
    QDialog::exec();

    return code;
}

auto ConfirmationDialog::on_btnCancel_clicked() -> void
{
    code = ExitCode::CANCEL;
    accept();
}

auto ConfirmationDialog::on_btnNo_clicked() -> void
{
    code = ExitCode::NO;
    accept();
}

auto ConfirmationDialog::on_btnYes_clicked() -> void
{
    code = ExitCode::YES;
    accept();
}

} // namespace Dialogs
