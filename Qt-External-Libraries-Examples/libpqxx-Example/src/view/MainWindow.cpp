#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "CustomersViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = new ViewModels::CustomersViewModel(ui->customersTableView);

    ui->customersTableView->setModel(customersViewModel);

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
