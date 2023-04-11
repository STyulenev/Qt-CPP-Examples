#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();
    productsViewModel = std::make_shared<ViewModels::ProductsViewModel>();
    ordersViewModel = std::make_shared<ViewModels::OrdersViewModel>();

    ui->customersTableView->setModel(customersViewModel.get());
    ui->productsTableView->setModel(productsViewModel.get());
    ui->ordersTableView->setModel(ordersViewModel.get());

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->productsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ordersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
