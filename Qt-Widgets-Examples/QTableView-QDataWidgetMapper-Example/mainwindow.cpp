#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<TableViewModel>();

    ui->tableView->setModel(viewModel.get());
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setDefaultSectionSize(100);
            //setSectionResizeMode(QHeaderView::);

    editForm = std::make_shared<EditForm>();
    editForm->setModel(viewModel.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_clicked(const QModelIndex& index) -> void
{
    //qDebug() << index.row();
    editForm->editCurrentRow(index.row());
    editForm->show();
}
