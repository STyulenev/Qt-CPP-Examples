#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "DAO.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DAO::getData();
}

MainWindow::~MainWindow()
{
    delete ui;
}
