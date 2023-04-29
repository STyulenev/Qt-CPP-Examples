#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <thread>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //updateCustomer();
    //updateProduct();

    /*customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();
    productsViewModel = std::make_shared<ViewModels::ProductsViewModel>();
    ordersViewModel = std::make_shared<ViewModels::OrdersViewModel>();*/

    /*std::thread threadOne ([]() -> void {
        Entities::Customer customer; // id ~ 4

        customer.setFirstName("Ron");
        customer.setLastName("Trump");
        customer.setEmail("ron_t_22@gmail.com");
        customer.setAge(22);

        DAO::insertCustomer(customer);
    });

    threadOne.detach();

    std::thread threadTwo ([]() -> void {
        Entities::Product product; // id ~ 6

        product.setType("Phone");
        product.setName("iPhone 19");
        product.setManufacturer("Gorizont Company");
        product.setCount(5);
        product.setPrice(79000);

        DAO::updateProduct(product);
    });

    threadTwo.detach();*/

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

auto MainWindow::updateCustomer() -> void
{
    Entities::Customer customer;

    customer.setId(4);
    customer.setFirstName("Ron");
    customer.setLastName("Tramp");
    customer.setEmail("ron_t_25@gmail.com");
    customer.setAge(25);

    //DAO::insertCustomer(customer);
}

auto MainWindow::updateProduct() -> void
{
    Entities::Product product;

    product.setId(6);
    product.setType("Phone");
    product.setName("iPhone 16");
    product.setManufacturer("Gorizont Company");
    product.setCount(5);
    product.setPrice(99000);

    //DAO::updateProduct(product);
}
