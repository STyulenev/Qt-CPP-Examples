#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ValidatorPool.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->nameLineEdit->setValidator(Setting::ValidatorPool::getSelf()->getValidator(Setting::ValidatorPool::Expression::NAME));
    ui->ipAddressLineEdit->setValidator(Setting::ValidatorPool::getSelf()->getValidator(Setting::ValidatorPool::Expression::IP));
    ui->emailLineEdit->setValidator(Setting::ValidatorPool::getSelf()->getValidator(Setting::ValidatorPool::Expression::EMAIL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_pushButton_clicked() -> void
{
    status = (ui->nameLineEdit->text() == "Name" && ui->ipAddressLineEdit->text() == "0.0.0.0");
}

} // namespace Views
