#pragma once

#include <QMainWindow>

#include <CustomersViewModel.h>

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
};
