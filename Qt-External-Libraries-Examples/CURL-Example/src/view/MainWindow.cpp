#include "MainWindow.h"
#include "./ui_MainWindow.h"

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
    ui->textEdit->clear();
    ui->textEdit->append(HTTPClient::getClient()->getServerCurrentTime());
}

auto MainWindow::on_pushButton_2_clicked() -> void
{
    ui->textEdit->clear();
    ui->textEdit->append(HTTPClient::getClient()->getServerUserList());
}

auto MainWindow::on_pushButton_3_clicked() -> void
{
    ui->textEdit->clear();
    ui->textEdit->append(HTTPClient::getClient()->postServerSendNewUser());
}


auto MainWindow::on_pushButton_4_clicked() -> void
{
    ui->textEdit->clear();
    ui->textEdit->append(HTTPClient::getClient()->deleteServerFirstUser());
}

