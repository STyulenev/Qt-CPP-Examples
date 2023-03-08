#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    systemTray = new QSystemTrayIcon(this);
    systemTray->setIcon(QIcon(":/icons/tray-icon.png"));
    systemTray->setToolTip("Qt-QSystemTrayIcon-Example");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction("Развернуть окно", this);
    QAction* quitAction = new QAction("Выход", this);

    connect(viewWindow, &QAction::triggered, this, &MainWindow::show);
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);

    menu->addAction(viewWindow);
    menu->addAction(quitAction);
    systemTray->setContextMenu(menu);

    systemTray->show();

    connect(systemTray, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::closeEvent(QCloseEvent* event) -> void
{
    systemTray->showMessage("Qt-QSystemTrayIcon-Example", "Приложение свернуто.", QSystemTrayIcon::Information);

    event->ignore();
    this->hide();
}

auto MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason) -> void
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if (this->isHidden()) {
            this->show();
        }
        break;
    case QSystemTrayIcon::MiddleClick:
        this->show();
        break;
    default:
        break;
    }
}
