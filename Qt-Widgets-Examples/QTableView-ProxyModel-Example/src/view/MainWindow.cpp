#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMenu>

#include "TableViewModel.h"
#include "ProxyTableViewModel.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = new ViewModels::TableViewModel(this);
    proxyModel = new ProxyModels::ProxyTableViewModel(this);
    proxyModel->setSourceModel(viewModel);
    ui->tableView->setModel(proxyModel);

    connect(ui->spinBoxMin, &QSpinBox::valueChanged, proxyModel, &ProxyModels::ProxyTableViewModel::setMinId);
    connect(ui->spinBoxMax, &QSpinBox::valueChanged, proxyModel, &ProxyModels::ProxyTableViewModel::setMaxId);
    connect(ui->lineEdit,   &QLineEdit::textChanged, proxyModel, &ProxyModels::ProxyTableViewModel::setName);

    connect(ui->radioButton_all, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyTableViewModel::Status::ALL);
    });
    connect(ui->radioButton_true, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyTableViewModel::Status::TRUE);
    });
    connect(ui->radioButton_false, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyTableViewModel::Status::FALSE);
    });

    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0, Qt::SortOrder::AscendingOrder);

    connect(ui->checkBox_id, &QCheckBox::toggled, [this](bool checked) -> void { // скрывает id колонку
        ui->tableView->setColumnHidden(0, !checked);
    });
    connect(ui->checkBox_name, &QCheckBox::toggled, [this](bool checked) -> void { // скрывает name колонку
        ui->tableView->setColumnHidden(1, !checked);
    });
    connect(ui->checkBox_number, &QCheckBox::toggled, [this](bool checked) -> void { // скрывает number колонку
        ui->tableView->setColumnHidden(2, !checked);
    });
    connect(ui->checkBox_status, &QCheckBox::toggled, [this](bool checked) -> void { // скрывает status колонку
        ui->tableView->setColumnHidden(3, !checked);
    });

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(proxyModel, &ProxyModels::ProxyTableViewModel::dataReady, [this](int count, int sumAge) -> void {
        ui->countValue->setText(QString("%1").arg(count));
        ui->sumAgeValue->setText(QString("%1").arg(sumAge));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_tableView_customContextMenuRequested(const QPoint& pos) -> void
{
    auto index = ui->tableView->indexAt(pos);

    if (index.isValid()) {
        QString columnName = ui->tableView->model()->headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString();

        std::shared_ptr<QMenu> menu = std::make_shared<QMenu>(this);

        QAction* sortByAscending  = new QAction(QString("Сортировать \"%1\" по возрастанию").arg(columnName), menu.get());
        QAction* sortByDescending = new QAction(QString("Сортировать \"%1\" по убыванию").arg(columnName), menu.get());

        connect(sortByAscending, &QAction::triggered, [this, &index]() -> void {
            ui->tableView->sortByColumn(index.column(), Qt::AscendingOrder);
        });

        connect(sortByDescending, &QAction::triggered, [this, &index]() -> void {
            ui->tableView->sortByColumn(index.column(), Qt::DescendingOrder);
        });

        menu->addAction(sortByAscending);
        menu->addAction(sortByDescending);

        menu->exec(QCursor::pos());
    }
}

} // namespace Views
