#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QImage>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableModel = new TableViewModel();

    ui->tableView->setModel(tableModel);

    // LimeReport::ICallbackDatasource* ds = m_report.dataManager()->createCallbackDatasource("ds");

    m_report.loadFromFile("path.../res/report.lrxml");

    m_report.dataManager()->addModel("tableModel", tableModel, false);
    m_report.dataManager()->setReportVariable("name1", ui->lineEdit->text());
    m_report.dataManager()->setReportVariable("name2", QImage(":/businessman.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::slotOneSlotDS(const LimeReport::CallbackInfo& info, QVariant& data) -> void
{
    QStringList columns;
    columns << "Name" << "Value" << "Image";
    switch (info.dataType) {
    case LimeReport::CallbackInfo::RowCount:
        data = 4;
        break;
    case LimeReport::CallbackInfo::ColumnCount:
        data = columns.size();
        break;
    case LimeReport::CallbackInfo::IsEmpty:
        data = false;
        break;
    case LimeReport::CallbackInfo::ColumnHeaderData: {
        data = columns.at(info.index);
        break;
    }
    case LimeReport::CallbackInfo::ColumnData:
        if (info.columnName == "Image")
            data = QImage(":/businessman.png");
        else {
            data = info.columnName + " " + QString::number(info.index);
        }
        break;
    default:
        break;
    }
}

auto MainWindow::on_pushButton_clicked() -> void
{
    m_report.previewReport();
}

auto MainWindow::on_pushButton_2_clicked() -> void
{
    m_report.designReport();
}
