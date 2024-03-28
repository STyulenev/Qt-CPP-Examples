#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QCompleter>

#include "ListViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listViewModel = new ViewModels::ListViewModel(this);

    completer = new QCompleter(this);
    completer->setModel(listViewModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    
    ui->searchLineEdit->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_okButton_clicked() -> void
{
    const QString text = ui->searchLineEdit->text();
    listViewModel->addData(text);
    ui->searchLineEdit->clear();
}

} // namespace Views
