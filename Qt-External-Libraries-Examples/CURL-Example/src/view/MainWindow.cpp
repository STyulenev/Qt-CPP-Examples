#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewModel = std::make_shared<ViewModels::TableViewModel>();
    ui->tableView->setModel(viewModel.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_pushButton_clicked() -> void
{
    qDebug() << HTTPClient::getClient()->getServerCurrentTime();
}

void MainWindow::on_pushButton_2_clicked()
{
    HTTPClient::getClient()->getServerUserList();
}

void MainWindow::on_pushButton_3_clicked()
{
    HTTPClient::getClient()->postServerSendNewUser();
}

