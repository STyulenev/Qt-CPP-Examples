#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableModel = new TableViewModel();

    ui->tableView->setModel(tableModel);

    LimeReport::ICallbackDatasource* ds = m_report.dataManager()->createCallbackDatasource("ds");

    /*connect(ds, &LimeReport::ICallbackDatasource::getCallbackData, this, &MainWindow::slotOneSlotDS);*/


   /* connect(ds, SIGNAL(getCallbackData(const LimeReport::CallbackInfo& info, QVariant &data)),
                       this, SLOT(slotOneSlotDS(const LimeReport::CallbackInfo& info, QVariant &data)));*/


    m_report.loadFromFile("C:/Work/5 Cool examples/TestUseLimonReport/12.lrxml");
    //m_report.loadFromString(...)

            //setCurrentReportsDir("C:/Work/5 Cool examples/TestUseLimonReport/12.lrxml");
    //m_report.dataManager()->

    m_report.dataManager()->addModel("tableModel", tableModel, false);
    m_report.dataManager()->setReportVariable("name1", ui->lineEdit->text());

    m_report.dataManager()->setReportVariable("name2", QImage(":/businessman.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOneSlotDS(const LimeReport::CallbackInfo& info, QVariant &data)
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
            default: break;
        }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << m_report.setReportLanguage(QLocale::Russian);

    m_report.previewReport();
}


void MainWindow::on_pushButton_2_clicked()
{
    m_report.designReport();

    //report->printReport(); to print report
}

