#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QDebug>

#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QColorDialog>

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

auto MainWindow::on_standartDialogButton_clicked() -> void
{
    QMessageBox dialog(QMessageBox::Question, tr("Dialog title"), tr("Dialog text"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    //dialog.setWindowFlags(Qt::FramelessWindowHint);

    switch (dialog.exec()) {
    case QMessageBox::Yes:
        qDebug() << "YES";
        break;
    case QMessageBox::No:
        qDebug() << "NO";
        break;
    case QMessageBox::Cancel:
        qDebug() << "CANCEL";
        break;
    default:
        return;
    }
}

auto MainWindow::on_customDialogButton_clicked() -> void
{
    Dialogs::ConfirmationDialog* dialog = new Dialogs::ConfirmationDialog(this);

    dialog->setFlags(Dialogs::DialogButtons::OK_BUTTON | Dialogs::DialogButtons::NO_BUTTON | Dialogs::DialogButtons::CANCEL_BUTTON);
    dialog->setTitle("Dialog title");
    dialog->setIcon(Dialogs::IconType::INFORMATION);

    switch (dialog->exec()) {
    case Dialogs::ExitCode::YES:
        qDebug() << "YES";
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

auto MainWindow::on_standartPathDialogButton_clicked() -> void
{
    const QStringList standartPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);

    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open Image"),
                                                (standartPath.isEmpty() ? QDir::currentPath() : standartPath.first()),
                                                tr("Image Files (*.png *.jpg *.bmp)"));

    qDebug() << path;
}

auto MainWindow::on_standartColorDialogButton_clicked() -> void
{
    QColor color = QColorDialog::getColor(Qt::black, this, tr("Choose color"));
    if (color.isValid() ) {
        qDebug() << color;
    }
}

} // namespace Views
