#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "TreeViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new ViewModels::TreeViewModel(this);

    ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
