#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model      = std::make_shared<Models::QComboBoxModel>();
    tableModel = std::make_shared<Models::TableViewModel>();

    ui->tableView->setModel(tableModel.get());

    mapper = std::make_shared<QDataWidgetMapper>();
    mapper->setOrientation(Qt::Horizontal);
    mapper->setModel(tableModel.get());
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_doubleClicked(const QModelIndex& index) -> void
{
    std::shared_ptr<QDialog>     dialog        = std::make_shared<QDialog>();
    std::shared_ptr<QGridLayout> grid          = std::make_shared<QGridLayout>(dialog.get());
    std::shared_ptr<QLabel>      idLabel       = std::make_shared<QLabel>("id:", dialog.get());
    std::shared_ptr<QLabel>      modelLabel    = std::make_shared<QLabel>("model:", dialog.get());
    std::shared_ptr<QLineEdit>   idLineEdit    = std::make_shared<QLineEdit>(dialog.get());
    std::shared_ptr<QComboBox>   modelComboBox = std::make_shared<QComboBox>(dialog.get());

    dialog->setWindowTitle("Dialog");
    idLineEdit->setText(index.data(Qt::DisplayRole).toString());

    modelComboBox->setModel(model.get());
    modelComboBox->setCurrentText(index.data(Qt::DisplayRole).toString());
    modelComboBox->setItemDelegate(new Delegates::QComboBoxDelegate(dialog.get()));

    std::shared_ptr<QDialogButtonBox> buttonBox = std::make_shared<QDialogButtonBox>(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Save");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");

    connect(buttonBox.get(), &QDialogButtonBox::accepted, dialog.get(), &QDialog::accept);
    connect(buttonBox.get(), &QDialogButtonBox::rejected, dialog.get(), &QDialog::reject);

    grid->addWidget(idLabel.get(),       0, 0);
    grid->addWidget(idLineEdit.get(),    0, 1);
    grid->addWidget(modelLabel.get(),    1, 0);
    grid->addWidget(modelComboBox.get(), 1, 1);
    grid->addWidget(buttonBox.get(),     2, 1);

    dialog->setLayout(grid.get());

    mapper->addMapping(idLineEdit.get(),    0);
    mapper->addMapping(modelComboBox.get(), 1);
    mapper->setCurrentIndex(index.row());

    if (dialog->exec() == QDialog::Accepted) {
        auto data = model->getItemForIndex(modelComboBox->currentIndex());

        auto index0 = tableModel->index(mapper->currentIndex(), 0);
        auto index1 = tableModel->index(mapper->currentIndex(), 1);

        tableModel->setData(index0, idLineEdit->text().toInt(), Qt::EditRole);
        tableModel->setData(index1, QVariant::fromValue(data),  Qt::EditRole);
    }
}
