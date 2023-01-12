#pragma once

#include <QMainWindow>

// View models
#include <TableViewModelForSimpleDelegates.h>
#include <TableViewModelForStyledDelegates.h>
#include <TableViewModelForCustomDelegates.h>

// Custom delegates
#include <CustomRadioButtonDelegate.h>
#include <CustomFileEditorDelegate.h>
#include <CustomColorEditorDelegate.h>

// Simple delegates
#include <ComboBoxDelegate.h>
#include <DateBoxDelegate.h>
#include <DoubleSpinBoxDelegate.h>
#include <LineEditDelegate.h>
#include <MultiLineTextDelegate.h>
#include <ReadOnlyDelegate.h>
#include <SpinBoxDelegate.h>
#include <TimeBoxDelegate.h>
#include <SliderDelegate.h>

// Styled delegates
#include <ImageDelegate.h>
#include <StyledSliderDelegate.h>
#include <CheckBoxDelegate.h>

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
    std::shared_ptr<ViewModels::TableViewModelForCustomDelegates> viewModelCustom;
};
