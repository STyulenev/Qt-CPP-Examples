#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QFileDialog>
#include <QMessageBox>

// QXlsx
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    modelSaveExample = std::make_shared<ViewModels::TableViewModel>();
    modelSaveExample->setDefaultData();
    ui->tableView->setModel(modelSaveExample.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_saveButton_clicked() -> void
{
    QXlsx::Document xlsxW;

    QXlsx::Format headerFormat;
    headerFormat.setVerticalAlignment(QXlsx::Format::VerticalAlignment::AlignVCenter);
    headerFormat.setHorizontalAlignment(QXlsx::Format::HorizontalAlignment::AlignHCenter);
    headerFormat.setFontBold(true);
    headerFormat.setFontColor(Qt::black);
    headerFormat.setPatternBackgroundColor(Qt::gray);

    const int row = 1;
    const int col = 1;
    const int columnCount = ui->tableView->model()->columnCount();
    const int rowCount    = ui->tableView->model()->rowCount();

    // Save headers
    for (int i = 0; i < columnCount; ++i) {
        xlsxW.write(row, col + i, ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole), headerFormat);
    }

    // Save data
    for (int i = 0; i < columnCount; ++i) {
        for (int j = 0; j < rowCount; ++j) {
            xlsxW.write(row + 1 + j, col + i, ui->tableView->model()->data(ui->tableView->model()->index(j, i), Qt::DisplayRole));
        }
    }

    xlsxW.write(row + 2 + rowCount, col, "Sum age:");
    xlsxW.write(row + 2 + rowCount, col + 1, QString("=SUM(B%1:B%2)").arg(row + 1).arg(row + rowCount));

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "C:/", tr("Excel (*.xlsx)"));

    if (fileName.isEmpty()) {
        QMessageBox::critical(nullptr, "Error saving", "File name is empty!");
    } else {
        if (xlsxW.saveAs(fileName)) {
            QMessageBox::information(nullptr, "Message", "File was save!");
        } else {
            QMessageBox::critical(nullptr, "Error saving", "Failed to write xlsx file!\nin" + fileName);
        }
    }
}

auto MainWindow::on_loadButton_clicked() -> void
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:/", tr("Excel (*.xlsx)"));

    QXlsx::Document xlsxR(fileName);

    if (xlsxR.load()) {
        int col = 1;
        int row = 2;

        QVector<ViewModels::TestModel> model;

        for (;;) {
            QXlsx::Cell* left  = xlsxR.cellAt(row, col);
            QXlsx::Cell* right = xlsxR.cellAt(row, col + 1);

            if (left == NULL || right == NULL) {
                break;
            } else {
                model.append({ left->readValue().toString(), right->readValue().toInt() });
                ++row;
            }
        }

        modelLoadExample = std::make_shared<ViewModels::TableViewModel>(model);
        ui->tableView_2->setModel(modelLoadExample.get());
    } else {
        QMessageBox::critical(nullptr, "Error saving", "Failed to write xlsx file!\nin" + fileName);
    }
}
