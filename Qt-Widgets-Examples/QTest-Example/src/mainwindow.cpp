#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nameValidator = std::make_shared<QRegularExpressionValidator>(QRegularExpression("^[A-Za-z]{10}$"));
    ipAddressValidator = std::make_shared<QRegularExpressionValidator>(
                QRegularExpression("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$"));
    emailValidator = std::make_shared<QRegularExpressionValidator>(QRegularExpression("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"));

    ui->nameLineEdit->setValidator(nameValidator.get());
    ui->ipAddressLineEdit->setValidator(ipAddressValidator.get());
    ui->emailLineEdit->setValidator(emailValidator.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    status = (ui->nameLineEdit->text() == "Name" && ui->ipAddressLineEdit->text() == "0.0.0.0");
}
