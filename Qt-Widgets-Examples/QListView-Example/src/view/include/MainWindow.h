#pragma once

#include <QMainWindow>

#include <ListViewModel.h>
#include "ListDelegate.h"

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
    std::shared_ptr<ViewModels::ListViewModel> listViewModel;
};
