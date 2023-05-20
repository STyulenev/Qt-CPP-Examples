#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <thread>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::thread threadThree ([this]() -> void {
        customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();
    });

    std::thread threadFour ([this]() -> void {
        productsViewModel = std::make_shared<ViewModels::ProductsViewModel>();
    });

    std::thread threadFive ([this]() -> void {
        ordersViewModel = std::make_shared<ViewModels::OrdersViewModel>();
    });

    threadThree.join();
    threadFour.join();
    threadFive.join();

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
