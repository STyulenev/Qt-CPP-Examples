#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>

#include "TableModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableModel = new ViewModels::TableModel("test", this);

    ui->tableView->setModel(tableModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_customContextMenuRequested(const QPoint& pos) -> void
{
    const int column = ui->tableView->horizontalHeader()->logicalIndexAt(pos);
    const int row    = ui->tableView->verticalHeader()->logicalIndexAt(pos);

    QString columnName = tableModel->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();

    std::shared_ptr<QMenu> menu = std::make_shared<QMenu>();
    QAction* addColumn    = new QAction(QString("Добавить столбец"), menu.get());
    QAction* deleteColumn = new QAction(QString("Удалить столбец \"%1\"").arg(columnName), menu.get());
    QAction* addRow       = new QAction(QString("Добавить строку"), menu.get());
    QAction* deleteRow    = new QAction(QString("Удалить строку \"%1\"").arg(row + 1), menu.get());

    QVector<QMetaObject::Connection> connections;

    connections << connect(addColumn, &QAction::triggered, this, [this]() -> void {
        std::shared_ptr<QDialog> dialog = std::make_shared<QDialog>();
        QGridLayout* grid        = new QGridLayout(dialog.get());
        QLabel*      columnLabel = new QLabel("Название столбца:", dialog.get());
        QLabel*      typeLabel   = new QLabel("Тип:", dialog.get());
        QLineEdit*   columnEdit  = new QLineEdit(dialog.get());
        QComboBox*   typeCombo   = new QComboBox(dialog.get());

        dialog->setWindowTitle("Вставка столбца");

        typeCombo->addItems({ "integer", "double precision", "character varying(200)", "boolean", "date", "time without time zone" });

        QDialogButtonBox* buttonBox = new QDialogButtonBox(dialog.get()); // QDialogButtonBox::Ok | QDialogButtonBox::Cancel
        QFlags<QDialogButtonBox::StandardButton> flags = QDialogButtonBox::Ok | QDialogButtonBox::Cancel;
        buttonBox->setStandardButtons(flags);
        buttonBox->button(QDialogButtonBox::Ok)->setText("Вставить");
        buttonBox->button(QDialogButtonBox::Cancel)->setText("Отмена");

        connect(buttonBox, &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);

        grid->addWidget(columnLabel, 0, 0);
        grid->addWidget(columnEdit,  0, 1);
        grid->addWidget(typeLabel,   1, 0);
        grid->addWidget(typeCombo,   1, 1);
        grid->addWidget(buttonBox,   2, 1);

        dialog->setLayout(grid);

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

        disconnect(buttonBox, &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
        disconnect(buttonBox, &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);
    });

    if (column < 0) {
        deleteColumn->setDisabled(true);
    } else {
        connections << connect(deleteColumn, &QAction::triggered, this, [this, columnName]() -> void {
            tableModel->deleteColumn(columnName);
        });
    }

    connections << connect(addRow, &QAction::triggered, this, [this]() -> void {
        tableModel->addRow();
    });

    if (row < 0) {
        deleteRow->setDisabled(true);
    } else {
        connections << connect(deleteRow, &QAction::triggered, this, [this, row]() -> void {
            tableModel->deleteRow(row);
        });
    }

    menu->addAction(addColumn);
    menu->addAction(deleteColumn);
    menu->addSeparator();
    menu->addAction(addRow);
    menu->addAction(deleteRow);

    menu->exec(QCursor::pos());

    std::for_each(connections.begin(), connections.end(), [](auto& action) -> void { disconnect(action); });
}

} // namespace Views
