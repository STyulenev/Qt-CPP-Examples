#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = std::make_shared<ViewModel::TreeViewModel>();

    ui->treeView->setModel(model.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

