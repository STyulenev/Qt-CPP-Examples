#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QDebug>
#include "ConfirmationDialog.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_dialogButton_clicked() -> void
{
    Dialogs::ConfirmationDialog* dialog = new Dialogs::ConfirmationDialog(this);

    dialog->setFlags(Dialogs::DialogButtons::OK_BUTTON | Dialogs::DialogButtons::NO_BUTTON | Dialogs::DialogButtons::CANCEL_BUTTON);
    dialog->setTitle("Dialog title");
    dialog->setIcon(Dialogs::IconType::INFORMATION);

    switch (dialog->exec()) {
    case Dialogs::ExitCode::YES:
        qDebug() << "OK";
        break;
    case Dialogs::ExitCode::NO:
        qDebug() << "NO";
        break;
    case Dialogs::ExitCode::CANCEL:
        qDebug() << "CANCEL";
        break;
    default:
        break;
    }

    delete dialog;
}

} // namespace Views
