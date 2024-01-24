#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class CustomersViewModel;
    class ProductsViewModel;
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
    ViewModels::ProductsViewModel* productsViewModel;

};

} // namespace Views
