#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ApplicationSettings.h"
#include "Caretaker.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto state = Settings::ApplicationSettings::getSetting()->getMainWindowsSetting();

    resize(state.first);
    restoreState(state.second);

    QString name;
    QString surname;
    QString description;

    Settings::ApplicationSettings::getSetting()->getFieldsData(name, surname, description);

    ui->nameEdit->setText(name);
    ui->surnameEdit->setText(surname);
    ui->descriptionEdit->setText(description);

    originator = new Settings::Originator(name, surname, description);
    caretaker = new Settings::Caretaker(originator);

    caretaker->save();
}

MainWindow::~MainWindow()
{
    Settings::ApplicationSettings::getSetting()->setMainWindowsSetting(size(), saveState());

    QString name = ui->nameEdit->text();
    QString surname = ui->surnameEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    Settings::ApplicationSettings::getSetting()->setFieldsData(name, surname, description);

    delete originator;
    delete caretaker;
    delete ui;
}

void MainWindow::setSetting()
{
    std::pair<bool, bool> statuses = caretaker->getStatus();
    ui->undoButton->setEnabled(statuses.first);
    ui->redoButton->setEnabled(statuses.second);
}

auto MainWindow::on_saveButton_clicked() -> void
{
    originator->setName(ui->nameEdit->text());
    originator->setSurname(ui->surnameEdit->text());
    originator->setDescription(ui->descriptionEdit->toPlainText());

    caretaker->save();

    setSetting();
}

auto MainWindow::on_undoButton_clicked() -> void
{
    if (caretaker->previous()) {
        ui->nameEdit->setText(originator->name());
        ui->surnameEdit->setText(originator->surname());
        ui->descriptionEdit->setText(originator->description());

        setSetting();
    }
}

auto MainWindow::on_redoButton_clicked() -> void
{
    if (caretaker->next()) {
        ui->nameEdit->setText(originator->name());
        ui->surnameEdit->setText(originator->surname());
        ui->descriptionEdit->setText(originator->description());

        setSetting();
    }
}

} // namespace Views
