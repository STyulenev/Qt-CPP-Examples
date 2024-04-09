#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QValidator>
#include <QRegularExpression>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 99, 1, this); // 00.0 - 99.9
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEditDouble->setValidator(doubleValidator);
    ui->lineEditDouble->setMaxLength(4);

    QIntValidator* intValidator = new QIntValidator(0, 999, this); // 000 - 999
    ui->lineEditInt->setValidator(intValidator);
    ui->lineEditInt->setMaxLength(3);

    QRegularExpression regExp("^[0-9]{1,2}[.,][0-9]{1,2}+$"); // 00.00 - 99.99
    QRegularExpressionValidator* regExpValidator = new QRegularExpressionValidator(regExp, this);
    ui->lineEditRegExp->setValidator(regExpValidator);
    ui->lineEditRegExp->setMaxLength(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
