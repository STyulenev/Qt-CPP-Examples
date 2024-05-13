#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "TableViewModel.h"
#include "CustomHeaderView.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = new ViewModels::TableViewModel(this);
    ui->tableView->setModel(viewModel);

    header = new Views::CustomHeaderView(Qt::Horizontal, ui->tableView);
    ui->tableView->setHorizontalHeader(header);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
