#include "MainWindow.h"
#include "./ui_MainWindow.h"

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
#include <StyledPieChartDelegate.h>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    { // Simple delegates for tableView
        viewModelSimple = new ViewModels::TableViewModelForSimpleDelegates(this);

        ui->tableView->setModel(viewModelSimple);

        ui->tableView->setItemDelegateForColumn(0, new SimpleDelegates::ReadOnlyDelegate());
        ui->tableView->setItemDelegateForColumn(1, new SimpleDelegates::LineEditDelegate());
        ui->tableView->setItemDelegateForColumn(2, new SimpleDelegates::SpinBoxDelegate());
        ui->tableView->setItemDelegateForColumn(3, new SimpleDelegates::DoubleSpinBoxDelegate());
        ui->tableView->setItemDelegateForColumn(4, new SimpleDelegates::TimeBoxDelegate());
        ui->tableView->setItemDelegateForColumn(5, new SimpleDelegates::DateBoxDelegate());
        ui->tableView->setItemDelegateForColumn(6, new SimpleDelegates::SliderDelegate());
        ui->tableView->setItemDelegateForColumn(7, new SimpleDelegates::ComboBoxDelegate({ "A", "B", "C", "D" }));
        ui->tableView->setItemDelegateForColumn(8, new SimpleDelegates::MultiLineTextDelegate());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    { // Styled delegates for tableView
        viewModelStyled = new ViewModels::TableViewModelForStyledDelegates(this);

        ui->tableView_2->setModel(viewModelStyled);

        ui->tableView_2->setItemDelegateForColumn(0, new StyledDelegates::StyledSliderDelegate());
        ui->tableView_2->setItemDelegateForColumn(1, new StyledDelegates::ImageDelegate());
        ui->tableView_2->setItemDelegateForColumn(2, new StyledDelegates::CheckBoxDelegate());
        ui->tableView_2->setItemDelegateForColumn(3, new StyledDelegates::StyledPieChartDelegate());

        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    { // Custom delegates for tableView viewModelCustom;
        viewModelCustom = new ViewModels::TableViewModelForCustomDelegates(this);

        ui->tableView_3->setModel(viewModelCustom);

        ui->tableView_3->setItemDelegateForColumn(0, new CustomDelegates::CustomRadioButtonDelegate());
        ui->tableView_3->setItemDelegateForColumn(1, new CustomDelegates::CustomFileEditorDelegate());
        ui->tableView_3->setItemDelegateForColumn(2, new CustomDelegates::CustomColorEditorDelegate());

        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
