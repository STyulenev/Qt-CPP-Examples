#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : 
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->insertNewCustomer();
    this->insertNewProduct();

    this->updateCustomer();
    this->updateProduct();

    DAO::deleteCustomer(4);
    DAO::deleteProduct(6);

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

auto MainWindow::insertNewCustomer() -> void
{
    Entities::Customer customer; // id ~ 4

    customer.setFirstName("Ron");
    customer.setLastName("Trump");
    customer.setEmail("ron_t_22@gmail.com");
    customer.setAge(22);

    DAO::insertCustomer(customer);
}

auto MainWindow::insertNewProduct() -> void
{
    Entities::Product product; // id ~ 6

    product.setType("Phone");
    product.setName("iPhone 19");
    product.setManufacturer("Gorizont Company");
    product.setCount(5);
    product.setPrice(79000);

    DAO::updateProduct(product);
}

auto MainWindow::updateCustomer() -> void
{
    Entities::Customer customer;

    customer.setId(4);
    customer.setFirstName("Ron");
    customer.setLastName("Tramp");
    customer.setEmail("ron_t_25@gmail.com");
    customer.setAge(25);

    DAO::insertCustomer(customer);
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

    DAO::updateProduct(product);
}
