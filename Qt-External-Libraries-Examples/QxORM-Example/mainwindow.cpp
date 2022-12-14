#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();
    ordersViewModel    = std::make_shared<ViewModels::OrdersViewModel>();
    productsViewModel  = std::make_shared<ViewModels::ProductsViewModel>();

    ui->customersTableView->setModel(customersViewModel.get());
    ui->ordersTableView->setModel(ordersViewModel.get());
    ui->productsTableView->setModel(productsViewModel.get());

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ordersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->productsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
