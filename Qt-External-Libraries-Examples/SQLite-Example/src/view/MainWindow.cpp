#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "PersonsViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    personsViewModel = new ViewModels::PersonsViewModel(this);

    ui->personsTableView->setModel(personsViewModel);
    ui->personsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
