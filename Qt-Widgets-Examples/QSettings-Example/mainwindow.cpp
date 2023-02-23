#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto state = Setting::getSetting()->getMainWindowsSetting();

    resize(state.first);
    restoreState(state.second);

    QString name;
    QString surname;
    QString description;

    Setting::getSetting()->getFieldsData(name, surname, description);

    ui->nameEdit->setText(name);
    ui->surnameEdit->setText(surname);
    ui->descriptionEdit->setText(description);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_saveButton_clicked() -> void
{
    Setting::getSetting()->setMainWindowsSetting(size(), saveState());

    QString name = ui->nameEdit->text();
    QString surname = ui->surnameEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    Setting::getSetting()->setFieldsData(name, surname, description);
}
