#include "MainWindow.h"
#include "./ui_MainWindow.h"

namespace View {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<ViewModels::TableViewModel>();

    ui->tableView->setModel(viewModel.get());
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setDefaultSectionSize(100);

    editForm = std::make_shared<EditForm>();
    editForm->setModel(viewModel.get());
    editForm->setWindowModality(Qt::WindowModality::ApplicationModal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_customContextMenuRequested(const QPoint& pos) -> void
{
    int row = ui->tableView->verticalHeader()->logicalIndexAt(pos);

    std::shared_ptr<QMenu> menu = std::make_shared<QMenu>(this);
    std::shared_ptr<QAction> editRow      = std::make_shared<QAction>(QString("Edit row"), this);
    std::shared_ptr<QAction> addRowBefore = std::make_shared<QAction>(QString("Add row before"), this);
    std::shared_ptr<QAction> addRowAfter  = std::make_shared<QAction>(QString("Add row after"), this);
    std::shared_ptr<QAction> addRowStart  = std::make_shared<QAction>(QString("Add row to start"), this);
    std::shared_ptr<QAction> addRowEnd    = std::make_shared<QAction>(QString("Add row to the end"), this);
    std::shared_ptr<QAction> deleteRow    = std::make_shared<QAction>(QString("Delete row"), this);

    if (row > -1 && row < ui->tableView->model()->rowCount()) {
        connect(editRow.get(), &QAction::triggered, [this, &row]() -> void {
            editForm->editCurrentRow(row);
            editForm->show();
        });

        connect(deleteRow.get(), &QAction::triggered, [this, &row]() -> void {
            ui->tableView->model()->removeRow(row);
        });
    } else {
        editRow->setDisabled(true);
        deleteRow->setDisabled(true);
    }

    if (row >= 0) {
        connect(addRowBefore.get(), &QAction::triggered, [this, &row]() -> void {
            ui->tableView->model()->insertRow(row);
            editForm->editCurrentRow(row);
            editForm->show();
        });
    } else {
        addRowBefore->setDisabled(true);
    }

    if (row >= 0 && row < ui->tableView->model()->rowCount()) {
        connect(addRowAfter.get(), &QAction::triggered, [this, &row]() -> void {
            ui->tableView->model()->insertRow(row + 1);
            editForm->editCurrentRow(row + 1);
            editForm->show();
        });
    } else {
        addRowAfter->setDisabled(true);
    }

    connect(addRowStart.get(), &QAction::triggered, [this]() -> void {
        ui->tableView->model()->insertRow(0);
        editForm->editCurrentRow(0);
        editForm->show();
    });

    connect(addRowEnd.get(), &QAction::triggered, [this]() -> void {
        int row = ui->tableView->model()->rowCount();
        ui->tableView->model()->insertRow(row);
        editForm->editCurrentRow(row);
        editForm->show();
    });

    menu->addAction(editRow.get());
    menu->addSeparator();
    menu->addAction(addRowBefore.get());
    menu->addAction(addRowAfter.get());
    menu->addAction(addRowStart.get());
    menu->addAction(addRowEnd.get());
    menu->addSeparator();
    menu->addAction(deleteRow.get());

    menu->exec(QCursor::pos());
}

} // namespace View
