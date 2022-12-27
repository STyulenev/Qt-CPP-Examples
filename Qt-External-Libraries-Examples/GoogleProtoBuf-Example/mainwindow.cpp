#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "person.pb.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    google_protobuf_example::Person person;

    person.set_name("Alex");
    person.set_last_name("Smith");
    person.set_age(19);
    person.set_sex(google_protobuf_example::Person::MALE);

    std::string message;
    person.SerializeToString(&message);

    qDebug() << message.c_str();
}

MainWindow::~MainWindow()
{
    delete ui;
}

