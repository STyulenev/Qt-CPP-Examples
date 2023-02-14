#pragma once

#include <QMainWindow>

#include <LimeReport>
#include <LRCallbackDS>

#include <TableViewModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void slotOneSlotDS(const LimeReport::CallbackInfo& info, QVariant &data);

private:
    Ui::MainWindow *ui;
    TableViewModel* tableModel;

    LimeReport::ReportEngine m_report;
};
