#pragma once

#include <QMainWindow>

#include <view-model/TableViewModelForSimpleDelegates.h>

#include <simple-delegates/ComboBoxDelegate.h>
#include <simple-delegates/DateBoxDelegate.h>
#include <simple-delegates/DoubleSpinBoxDelegate.h>
#include <simple-delegates/LineEditDelegate.h>
#include <simple-delegates/ReadOnlyDelegate.h>
#include <simple-delegates/SpinBoxDelegate.h>
#include <simple-delegates/TimeBoxDelegate.h>
#include <simple-delegates/SliderDelegate.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<TableViewModelForSimpleDelegates> viewModel;
};
