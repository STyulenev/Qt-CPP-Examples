#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMenu>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableModel = std::make_shared<ViewModels::TableModel>("test");

    ui->tableView->setModel(tableModel.get());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint& pos)
{
    int column = ui->tableView->horizontalHeader()->logicalIndexAt(pos);
    int row    = ui->tableView->verticalHeader()->logicalIndexAt(pos);

    QString columnName = tableModel->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();

    std::shared_ptr<QMenu> menu = std::make_shared<QMenu>(this);
    std::shared_ptr<QAction> addColumn    = std::make_shared<QAction>(QString("Добавить столбец"), this);
    std::shared_ptr<QAction> deleteColumn = std::make_shared<QAction>(QString("Удалить столбец \"%1\"").arg(columnName), this);
    std::shared_ptr<QAction> addRow       = std::make_shared<QAction>(QString("Добавить строку"), this);
    std::shared_ptr<QAction> deleteRow    = std::make_shared<QAction>(QString("Удалить строку \"%1\"").arg(row + 1), this);

    QVector<QMetaObject::Connection> connections;

    connections << connect(addColumn.get(), &QAction::triggered, [this]() -> void {
        std::shared_ptr<QDialog>     dialog      = std::make_shared<QDialog>();
        std::shared_ptr<QGridLayout> grid        = std::make_shared<QGridLayout>();
        std::shared_ptr<QLabel>      columnLabel = std::make_shared<QLabel>("Название столбца:");
        std::shared_ptr<QLabel>      typeLabel   = std::make_shared<QLabel>("Тип:");
        std::shared_ptr<QLineEdit>   columnEdit  = std::make_shared<QLineEdit>();
        std::shared_ptr<QComboBox>   typeCombo   = std::make_shared<QComboBox>();

        dialog->setWindowTitle("Вставка столбца");

        typeCombo->addItems({ "integer", "double precision", "character varying(200)", "boolean", "date", "time without time zone" });

        std::shared_ptr<QDialogButtonBox> buttonBox = std::make_shared<QDialogButtonBox>(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        buttonBox->button(QDialogButtonBox::Ok)->setText("Вставить");
        buttonBox->button(QDialogButtonBox::Cancel)->setText("Отмена");

        connect(buttonBox.get(), &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
        connect(buttonBox.get(), &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);

        grid->addWidget(columnLabel.get(), 0, 0);
        grid->addWidget(columnEdit.get(),  0, 1);
        grid->addWidget(typeLabel.get(),   1, 0);
        grid->addWidget(typeCombo.get(),   1, 1);
        grid->addWidget(buttonBox.get(),   2, 1);

        dialog->setLayout(grid.get());

        int result = dialog->exec();
        if (result == QDialog::Accepted) {
            try {
                QString columnName = columnEdit->text();
                QString columnType = typeCombo->currentText();

                if (columnName.isEmpty()) throw QString("Название колонки не может быть пустым");

                tableModel->addColumn(columnName, columnType);
            }  catch (QString& error) {
                QMessageBox::critical(this, "Ошибка", error);
            }
        }

        disconnect(buttonBox.get(), &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
        disconnect(buttonBox.get(), &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);
    });

    if (column < 0) {
        deleteColumn->setDisabled(true);
    } else {
        connections << connect(deleteColumn.get(), &QAction::triggered, [this, columnName]() -> void {
            tableModel->deleteColumn(columnName);
        });
    }

    connections << connect(addRow.get(), &QAction::triggered, [this]() -> void {
        tableModel->addRow();
    });

    if (row < 0) {
        deleteRow->setDisabled(true);
    } else {
        connections << connect(deleteRow.get(), &QAction::triggered, [this, &row]() -> void {
            tableModel->deleteRow(row);
        });
    }

    menu->addAction(addColumn.get());
    menu->addAction(deleteColumn.get());
    menu->addSeparator();
    menu->addAction(addRow.get());
    menu->addAction(deleteRow.get());

    menu->exec(QCursor::pos());

    std::for_each(connections.begin(), connections.end(), [](auto& action) -> void { disconnect(action); });
}

