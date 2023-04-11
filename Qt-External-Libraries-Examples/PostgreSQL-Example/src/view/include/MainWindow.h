#pragma once

#include <QMainWindow>

#include <CustomersViewModel.h>
#include <ProductsViewModel.h>
#include <OrdersViewModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    std::shared_ptr<ViewModels::CustomersViewModel> customersViewModel;
    std::shared_ptr<ViewModels::ProductsViewModel>  productsViewModel;
    std::shared_ptr<ViewModels::OrdersViewModel>    ordersViewModel;
};
