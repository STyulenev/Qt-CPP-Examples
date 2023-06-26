#pragma once

#include <QMainWindow>
#include <QWidget>

#include <TableModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    void on_tableView_customContextMenuRequested(const QPoint& pos);

private:
    Ui::MainWindow* ui;
    std::shared_ptr<ViewModels::TableModel> tableModel;
};
