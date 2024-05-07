#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ListViewModel.h"
#include "ListDelegate.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listViewModel = new ViewModels::ListViewModel(this);
    ui->listView->setModel(listViewModel);

    ui->listView_2->setModel(listViewModel);
    ui->listView_2->setItemDelegateForColumn(0, new Delegates::ListDelegate(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
