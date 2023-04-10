#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();
    productsViewModel = std::make_shared<ViewModels::ProductsViewModel>();

    ui->customersTableView->setModel(customersViewModel.get());
    ui->productsTableView->setModel(customersViewModel.get());

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->productsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
