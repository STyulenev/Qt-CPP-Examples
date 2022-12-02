#pragma once

#include <QMainWindow>

// View models
#include <view-model/TableViewModelForSimpleDelegates.h>
#include <view-model/TableViewModelForStyledDelegates.h>

// Simple delegates
#include <simple-delegates/ComboBoxDelegate.h>
#include <simple-delegates/DateBoxDelegate.h>
#include <simple-delegates/DoubleSpinBoxDelegate.h>
#include <simple-delegates/LineEditDelegate.h>
#include <simple-delegates/ReadOnlyDelegate.h>
#include <simple-delegates/SpinBoxDelegate.h>
#include <simple-delegates/TimeBoxDelegate.h>
#include <simple-delegates/SliderDelegate.h>

// Styled delegates
#include <styled-delegates/ImageDelegate.h>
#include <styled-delegates/SliderDelegate.h>

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
    std::shared_ptr<ViewModels::TableViewModelForSimpleDelegates> viewModelSimple;
    std::shared_ptr<ViewModels::TableViewModelForStyledDelegates> viewModelStyled;
};
