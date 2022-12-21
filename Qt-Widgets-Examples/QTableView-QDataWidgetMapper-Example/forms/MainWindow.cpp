#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<ViewModels::TableViewModel>();

    ui->tableView->setModel(viewModel.get());
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setDefaultSectionSize(100);

    editForm = std::make_shared<EditForm>();
    editForm->setModel(viewModel.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_clicked(const QModelIndex& index) -> void
{
    editForm->editCurrentRow(index.row());
    editForm->setWindowModality(Qt::WindowModality::ApplicationModal);
    editForm->show();
}
