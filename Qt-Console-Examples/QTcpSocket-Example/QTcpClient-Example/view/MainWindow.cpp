#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "TcpSocket.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = qobject_cast<Transport::TcpSocket*>(qApp->property("TcpSocket").value<QObject*>());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString message = ui->lineEdit->text();

    emit socket->write(message.toLocal8Bit());

    ui->lineEdit->clear();
}

} // namespace Views
