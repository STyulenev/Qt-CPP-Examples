#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    { // Simple delegates for tableView
        viewModelSimple = std::make_shared<ViewModels::TableViewModelForSimpleDelegates>();

        ui->tableView->setModel(viewModelSimple.get());

        ui->tableView->setItemDelegateForColumn(0, new SimpleDelegates::ReadOnlyDelegate());
        ui->tableView->setItemDelegateForColumn(1, new SimpleDelegates::LineEditDelegate());
        ui->tableView->setItemDelegateForColumn(2, new SimpleDelegates::SpinBoxDelegate());
        ui->tableView->setItemDelegateForColumn(3, new SimpleDelegates::DoubleSpinBoxDelegate());
        ui->tableView->setItemDelegateForColumn(4, new SimpleDelegates::TimeBoxDelegate());
        ui->tableView->setItemDelegateForColumn(5, new SimpleDelegates::DateBoxDelegate());
        ui->tableView->setItemDelegateForColumn(6, new SimpleDelegates::SliderDelegate());
        ui->tableView->setItemDelegateForColumn(7, new SimpleDelegates::ComboBoxDelegate({ "A", "B", "C", "D" }));

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }


    { // Styled delegates for tableView
        viewModelStyled = std::make_shared<ViewModels::TableViewModelForStyledDelegates>();

        ui->tableView_2->setModel(viewModelStyled.get());

        ui->tableView_2->setItemDelegateForColumn(0, new StyledDelegates::SliderDelegate());
        ui->tableView_2->setItemDelegateForColumn(1, new StyledDelegates::ImageDelegate());
        ui->tableView_2->setItemDelegateForColumn(2, new StyledDelegates::CheckBoxDelegate());

        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

