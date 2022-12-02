#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<TableViewModelForSimpleDelegates>();

    ui->tableView->setModel(viewModel.get());

    ui->tableView->setItemDelegateForColumn(0, new SimpleDelegates::ReadOnlyDelegate());
    ui->tableView->setItemDelegateForColumn(1, new SimpleDelegates::LineEditDelegate());
    ui->tableView->setItemDelegateForColumn(2, new SimpleDelegates::SpinBoxDelegate());
    ui->tableView->setItemDelegateForColumn(3, new SimpleDelegates::DoubleSpinBoxDelegate());
    ui->tableView->setItemDelegateForColumn(4, new SimpleDelegates::TimeBoxDelegate());
    ui->tableView->setItemDelegateForColumn(5, new SimpleDelegates::DateBoxDelegate());
    ui->tableView->setItemDelegateForColumn(6, new SimpleDelegates::SliderDelegate());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

