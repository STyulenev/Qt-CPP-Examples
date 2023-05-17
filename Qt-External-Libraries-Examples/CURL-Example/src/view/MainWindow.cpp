#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*auto state = Setting::getSetting()->getMainWindowsSetting();

*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_pushButton_clicked() -> void
{
    qDebug() << HTTPClient::getClient()->getServerCurrentTime();
}

