#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "SplashScreen.h"

#include <QTimer>
#include <QDateTime>

#include "Navigator.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_navigator = std::make_shared<Navigator>(ui->stackedWidget, new Screens::SplashScreen());

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() -> void {
        ui->dateTimeLabel->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd-MM-yyyy dddd"));
    });
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
