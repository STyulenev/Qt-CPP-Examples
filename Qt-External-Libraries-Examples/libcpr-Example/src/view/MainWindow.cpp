#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "HTTPClient.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    httpClient = new Network::HTTPClient();

    connect(httpClient, &Network::AbstractHTTPClient::serverCurrentTime, this, [this] (QString answer) -> void {
            qDebug() << "Answer" << QThread::currentThreadId();
            ui->textEdit->clear();
            ui->textEdit->append(answer);
        });


    connect(httpClient, &Network::AbstractHTTPClient::serverUserList, this, [this] (QString answer) -> void {
        qDebug() << "Answer" << QThread::currentThreadId();
        ui->textEdit->clear();
        ui->textEdit->append(answer);
    });

    connect(httpClient, &Network::AbstractHTTPClient::error, this, [this] (QString error) -> void {
        qDebug() << "Error" << QThread::currentThreadId();
        ui->textEdit->clear();
        ui->textEdit->append(error);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_pushButton_clicked() -> void
{
    auto future = QtConcurrent::run(&Network::AbstractHTTPClient::getServerCurrentTime, httpClient);
}

auto MainWindow::on_pushButton_2_clicked() -> void
{
    auto future = QtConcurrent::run(&Network::AbstractHTTPClient::postServerSendNewUser, httpClient);
}

auto MainWindow::on_pushButton_3_clicked() -> void
{
    auto future = QtConcurrent::run(&Network::AbstractHTTPClient::getServerUserList, httpClient);
}

auto MainWindow::on_pushButton_4_clicked() -> void
{
    auto future = QtConcurrent::run(&Network::AbstractHTTPClient::deleteServerFirstUser, httpClient);
}

} // namespace Views
