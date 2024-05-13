#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "TableViewModel.h"
#include "QComboBoxDelegate.h"
#include "QComboBoxModel.h"

#include <QComboBox>
#include <QDataWidgetMapper>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model      = new Models::QComboBoxModel(this);
    tableModel = new Models::TableViewModel(this);

    ui->tableView->setModel(tableModel);

    mapper = new QDataWidgetMapper(this);
    mapper->setOrientation(Qt::Horizontal);
    mapper->setModel(tableModel);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_doubleClicked(const QModelIndex& index) -> void
{
    std::shared_ptr<QDialog> dialog = std::make_shared<QDialog>();
    QGridLayout* grid          = new QGridLayout(dialog.get());
    QLabel*      idLabel       = new QLabel("id:", dialog.get());
    QLabel*      modelLabel    = new QLabel("model:", dialog.get());
    QLineEdit*   idLineEdit    = new QLineEdit(dialog.get());
    QComboBox*   modelComboBox = new QComboBox(dialog.get());

    dialog->setWindowTitle("Dialog");
    idLineEdit->setText(index.data(Qt::DisplayRole).toString());

    modelComboBox->setModel(model);
    modelComboBox->setCurrentText(index.data(Qt::DisplayRole).toString());
    modelComboBox->setItemDelegate(new Delegates::QComboBoxDelegate(dialog.get()));

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, dialog.get());
    buttonBox->button(QDialogButtonBox::Ok)->setText("Save");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");

    connect(buttonBox, &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);

    grid->addWidget(idLabel,       0, 0);
    grid->addWidget(idLineEdit,    0, 1);
    grid->addWidget(modelLabel,    1, 0);
    grid->addWidget(modelComboBox, 1, 1);
    grid->addWidget(buttonBox,     2, 1);

    dialog->setLayout(grid);

    mapper->addMapping(idLineEdit,    0);
    mapper->addMapping(modelComboBox, 1);
    mapper->setCurrentIndex(index.row());

    if (dialog->exec() == QDialog::Accepted) {
        auto data = model->getItemForIndex(modelComboBox->currentIndex());

        auto index0 = tableModel->index(mapper->currentIndex(), 0);
        auto index1 = tableModel->index(mapper->currentIndex(), 1);

        tableModel->setData(index0, idLineEdit->text().toInt(), Qt::EditRole);
        tableModel->setData(index1, QVariant::fromValue(data),  Qt::EditRole);
    }
}

} // namespace Views
