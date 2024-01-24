#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "CustomersViewModel.h"
#include "ProductsViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = new ViewModels::CustomersViewModel(this);
    productsViewModel = new ViewModels::ProductsViewModel(this);

    ui->customersTableView->setModel(customersViewModel);
    ui->productsTableView->setModel(productsViewModel);

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->productsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
