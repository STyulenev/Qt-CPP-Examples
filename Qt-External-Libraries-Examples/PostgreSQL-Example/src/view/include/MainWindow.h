#pragma once

#include <QMainWindow>

#include <CustomersViewModel.h>
#include <ProductsViewModel.h>
#include <OrdersViewModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    std::shared_ptr<ViewModels::CustomersViewModel> customersViewModel;
    std::shared_ptr<ViewModels::ProductsViewModel>  productsViewModel;
    std::shared_ptr<ViewModels::OrdersViewModel>    ordersViewModel;

    auto updateCustomer() -> void;
    auto updateProduct() -> void;

};

} // namespace Views
