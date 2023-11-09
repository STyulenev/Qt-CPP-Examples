#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class CustomersViewModel;
    class ProductsViewModel;
    class OrdersViewModel;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    ViewModels::CustomersViewModel* customersViewModel;
    ViewModels::ProductsViewModel*  productsViewModel;
    ViewModels::OrdersViewModel*    ordersViewModel;

};

} // namespace Views
