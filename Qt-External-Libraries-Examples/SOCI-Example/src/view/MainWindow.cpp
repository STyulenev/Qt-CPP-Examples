#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Customer.h"
#include <QDebug>

#include <iostream>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try {
        soci::session sql(soci::postgresql, "dbname=test_db user=postgres password=tyulenev port=5432 host=localhost"); //


        qDebug() << "Successfully connected to \", " << "using \"" << sql.get_backend_name() << "\" backend.\n";

        //std::vector<Customer> customers;
        //sql << "SELECT * FROM customers", soci::into(customers);
        //qDebug() << customers.size();

        soci::rowset<Customer> rs = (sql.prepare << "SELECT * FROM customers");
        for (auto it = rs.begin(); it != rs.end(); it++) {
            Customer& i = *it;
            i.print();
        }

    } catch (const soci::soci_error& e) {
        std::cout << e.what() << std::endl;
        qDebug() << e.what();
    } catch (const std::runtime_error& e) {
        qDebug() <<  e.what() << "222";
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.\n";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

} //namespace Views
