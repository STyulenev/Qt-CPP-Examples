#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "HTTPClient.h"

#include <QPromise>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    httpClient = new Network::HTTPClient();

    connect(httpClient, &Network::AbstractHTTPClient::serverCurrentTime, this, [this] (QString a) -> void {
            qDebug() << "Answer" << QThread::currentThreadId();
            ui->textEdit->clear();
            ui->textEdit->append(a);
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

}

auto MainWindow::on_pushButton_3_clicked() -> void
{

}

auto MainWindow::on_pushButton_4_clicked() -> void
{

}

} // namespace Views
