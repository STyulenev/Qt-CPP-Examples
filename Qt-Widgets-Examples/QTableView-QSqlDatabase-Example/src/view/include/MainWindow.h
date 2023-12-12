#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace ViewModels {
    class CustomersViewModel;
    class ProductsViewModel;
    class OrdersViewModel;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow* ui;

    ViewModels::CustomersViewModel* customersViewModel;
    ViewModels::ProductsViewModel*  productsViewModel;
    ViewModels::OrdersViewModel*    ordersViewModel;

};

} // namespace Views
