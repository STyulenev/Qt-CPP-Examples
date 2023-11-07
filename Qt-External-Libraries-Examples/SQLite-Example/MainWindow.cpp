#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "DAO.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DAO dao;
    dao.openDatabase();
    dao.insertNewPerson();
    dao.selectPeople();
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
