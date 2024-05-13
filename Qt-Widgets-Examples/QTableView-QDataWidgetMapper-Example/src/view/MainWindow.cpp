#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "TableViewModel.h"
#include "EditForm.h"

namespace View {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = new ViewModels::TableViewModel(this);

    ui->tableView->setModel(viewModel);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setDefaultSectionSize(100);

    editForm = new EditForm();
    editForm->setModel(viewModel);
    editForm->setWindowModality(Qt::WindowModality::ApplicationModal);
}

MainWindow::~MainWindow()
{
    delete editForm;
    delete ui;
}

auto MainWindow::on_tableView_customContextMenuRequested(const QPoint& pos) -> void
{
    const int row = ui->tableView->verticalHeader()->logicalIndexAt(pos);

    std::shared_ptr<QMenu> menu = std::make_shared<QMenu>(this);
    QAction* editRow      = new QAction(QString("Edit row"), menu.get());
    QAction* addRowBefore = new QAction(QString("Add row before"), menu.get());
    QAction* addRowAfter  = new QAction(QString("Add row after"), menu.get());
    QAction* addRowStart  = new QAction(QString("Add row to start"), menu.get());
    QAction* addRowEnd    = new QAction(QString("Add row to the end"), menu.get());
    QAction* deleteRow    = new QAction(QString("Delete row"), menu.get());

    if (row > -1 && row < ui->tableView->model()->rowCount()) {
        connect(editRow, &QAction::triggered, menu.get(), [this, row]() -> void {
            editForm->editCurrentRow(row);
            editForm->show();
        });

        connect(deleteRow, &QAction::triggered, menu.get(), [this, row]() -> void {
            ui->tableView->model()->removeRow(row);
        });
    } else {
        editRow->setDisabled(true);
        deleteRow->setDisabled(true);
    }

    if (row >= 0) {
        connect(addRowBefore, &QAction::triggered, menu.get(), [this, row]() -> void {
            ui->tableView->model()->insertRow(row);
            editForm->editCurrentRow(row);
            editForm->show();
        });
    } else {
        addRowBefore->setDisabled(true);
    }

    if (row >= 0 && row < ui->tableView->model()->rowCount()) {
        connect(addRowAfter, &QAction::triggered, menu.get(), [this, row]() -> void {
            ui->tableView->model()->insertRow(row + 1);
            editForm->editCurrentRow(row + 1);
            editForm->show();
        });
    } else {
        addRowAfter->setDisabled(true);
    }

    connect(addRowStart, &QAction::triggered, menu.get(), [this]() -> void {
        ui->tableView->model()->insertRow(0);
        editForm->editCurrentRow(0);
        editForm->show();
    });

    connect(addRowEnd, &QAction::triggered, menu.get(), [this]() -> void {
        const int row = ui->tableView->model()->rowCount();
        ui->tableView->model()->insertRow(row);
        editForm->editCurrentRow(row);
        editForm->show();
    });

    menu->addAction(editRow);
    menu->addSeparator();
    menu->addAction(addRowBefore);
    menu->addAction(addRowAfter);
    menu->addAction(addRowStart);
    menu->addAction(addRowEnd);
    menu->addSeparator();
    menu->addAction(deleteRow);

    menu->exec(QCursor::pos());
}

} // namespace View
