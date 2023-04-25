#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listViewModel = std::make_shared<ViewModels::ListViewModel>();
    ui->listView->setModel(listViewModel.get());

    ui->listView_2->setModel(listViewModel.get());
    ui->listView_2->setItemDelegateForColumn(0, new Delegates::ListDelegate());
}

MainWindow::~MainWindow()
{
    delete ui;
}
