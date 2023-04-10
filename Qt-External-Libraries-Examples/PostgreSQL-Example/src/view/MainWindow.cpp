#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customersViewModel = std::make_shared<ViewModels::CustomersViewModel>();

    ui->customersTableView->setModel(customersViewModel.get());

    ui->customersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
