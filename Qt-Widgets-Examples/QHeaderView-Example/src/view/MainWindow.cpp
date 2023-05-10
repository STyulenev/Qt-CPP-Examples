#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<ViewModels::TableViewModel>();
    ui->tableView->setModel(viewModel.get());

    header = std::make_shared<ViewModels::HeaderViewTableModel>(Qt::Horizontal, ui->tableView);
    ui->tableView->setHorizontalHeader(header.get());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
