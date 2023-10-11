#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Customer.h"
#include "Product.h"
#include "Order.h"

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

        {
            soci::rowset<Entities::Customer> rs = (sql.prepare << "SELECT * FROM Customers ORDER BY id ASC;");
            for (auto it = rs.begin(); it != rs.end(); it++) {
                Entities::Customer& i = *it;
                i.print();
            }
        }

        {
            soci::rowset<Entities::Product> pr = (sql.prepare << "SELECT * FROM Products ORDER BY id ASC;");
            for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
                Entities::Product& i = *iterator;
                i.print();
            }
        }

        {
            soci::rowset<Entities::Order> pr = (sql.prepare << "SELECT * FROM Orders "
                                                               "JOIN Products as Products ON Products.id = Orders.product_id "
                                                               "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                                               "ORDER BY Orders.id ASC;");
            for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
                Entities::Order& i = *iterator;
                i.print();
            }
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
