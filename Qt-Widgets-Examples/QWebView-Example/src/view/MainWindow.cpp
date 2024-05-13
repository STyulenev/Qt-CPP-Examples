#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QDebug>

#include "Report.h"

#include <memory>

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

void MainWindow::on_createReportButton_clicked()
{
    std::shared_ptr<Print::ReportView> dialog = std::make_shared<Print::ReportView>();

    dialog->setTitle(ui->titleEdit->text());
    dialog->setFrom(ui->fromEdit->text());
    dialog->setTo(ui->toEdit->text());
    dialog->setMainText(ui->mainTextEdit->toPlainText());

    if (dialog->exec() == QDialog::Accepted) {
        // ..
    }
}

} // namespace Views
