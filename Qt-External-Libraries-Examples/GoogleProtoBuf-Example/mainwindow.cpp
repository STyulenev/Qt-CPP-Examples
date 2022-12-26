#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "generate/addressbook.pb.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tutorial::Person person;

    person.set_id(12);
}

MainWindow::~MainWindow()
{
    delete ui;
}

