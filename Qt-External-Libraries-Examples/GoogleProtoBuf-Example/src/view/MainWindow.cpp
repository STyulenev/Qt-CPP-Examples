#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "person.pb.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_pushButton_clicked() -> void
{
    google_protobuf_example::Person person;

    person.set_name(ui->firstNameLineEdit->text().toStdString());
    person.set_last_name(ui->lastNameLineEdit->text().toStdString());
    person.set_age(ui->ageSpinBox->value());

    switch (ui->sexComboBox->currentIndex()) {
    case 0:
        person.set_sex(google_protobuf_example::Person::MALE);
        break;
    case 1:
        person.set_sex(google_protobuf_example::Person::FEMALE);
        break;
    default:
        person.set_sex(google_protobuf_example::Person::UNKNOWN);
    }

    std::string message;
    person.SerializeToString(&message);

    /*int size = person.ByteSizeLong();
    char* array = new char[size];
    person.SerializeToArray(array, size);*/

    unpacker(message);
}

auto MainWindow::unpacker(std::string data) -> void
{
    ui->textEdit->clear();

    google_protobuf_example::Person person;
    person.ParseFromString(data);

    ui->textEdit->append(QString(person.name().c_str()));
    ui->textEdit->append(QString(person.last_name().c_str()));
    ui->textEdit->append(QString::number(person.age()));
    ui->textEdit->append(QString("%1").arg(person.sex() == google_protobuf_example::Person::MALE ? "Male" :
                                               person.sex() == google_protobuf_example::Person::FEMALE ? "Female" : "Unknown"));
}

