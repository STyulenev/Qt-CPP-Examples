#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = std::make_shared<ViewModels::TableViewModel>();
    proxyModel = std::make_shared<ProxyModels::ProxyModel>();
    proxyModel->setSourceModel(viewModel.get());
    ui->tableView->setModel(proxyModel.get());

    connect(ui->spinBoxMin, &QSpinBox::valueChanged, proxyModel.get(), &ProxyModels::ProxyModel::setMinId);
    connect(ui->spinBoxMax, &QSpinBox::valueChanged, proxyModel.get(), &ProxyModels::ProxyModel::setMaxId);
    connect(ui->lineEdit,   &QLineEdit::textChanged, proxyModel.get(), &ProxyModels::ProxyModel::setName);

    connect(ui->radioButton_all, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyModel::Status::ALL);
    });
    connect(ui->radioButton_true, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyModel::Status::TRUE);
    });
    connect(ui->radioButton_false, &QRadioButton::clicked, [this]() -> void {
        proxyModel->setStatus(ProxyModels::ProxyModel::Status::FALSE);
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

    connect(proxyModel.get(), &ProxyModels::ProxyModel::dataReady, [this](int count, int sumAge) -> void {
        ui->countValue->setText(QString::number(count));
        ui->sumAgeValue->setText(QString::number(sumAge));
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

        std::shared_ptr<QAction> sortByAscending  = std::make_shared<QAction>(QString("Сортировать \"%1\" по возрастанию").arg(columnName), this);
        std::shared_ptr<QAction> sortByDescending = std::make_shared<QAction>(QString("Сортировать \"%1\" по убыванию").arg(columnName), this);

        QMetaObject::Connection actionOne = connect(sortByAscending.get(), &QAction::triggered, [this, &index]() -> void {
            ui->tableView->sortByColumn(index.column(), Qt::AscendingOrder);
        });

        QMetaObject::Connection actionTwo = connect(sortByDescending.get(), &QAction::triggered, [this, &index]() -> void {
            ui->tableView->sortByColumn(index.column(), Qt::DescendingOrder);
        });

        menu->addAction(sortByAscending.get());
        menu->addAction(sortByDescending.get());

        menu->exec(QCursor::pos());

        disconnect(actionOne);
        disconnect(actionTwo);
    }
}
