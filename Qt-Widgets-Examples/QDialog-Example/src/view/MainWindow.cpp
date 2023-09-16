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

auto MainWindow::on_pushButton_clicked() -> void
{
    Dialogs::ConfirmationDialog* dialog = new Dialogs::ConfirmationDialog(this);

    dialog->setFlags(DialogButtons::OK_BUTTON | DialogButtons::NO_BUTTON | DialogButtons::CANCEL_BUTTON);
    dialog->setTitle("Dialog title");

    switch (dialog->exec()) {
    case ExitCode::YES:
        qDebug() << "OK";
        break;
    case ExitCode::NO:
        qDebug() << "NO";
        break;
    case ExitCode::CANCEL:
        qDebug() << "CANCEL";
        break;
    default:
        break;
    }

    delete dialog;
}

} // namespace Views
