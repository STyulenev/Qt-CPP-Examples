#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>

#include <view-model/TableViewModel.h>
#include <proxy-model/ProxyModel.h>

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
    auto on_tableView_customContextMenuRequested(const QPoint& pos) -> void;

private:
    Ui::MainWindow* ui;
    std::shared_ptr<ViewModels::TableViewModel> viewModel;
    std::shared_ptr<ProxyModels::ProxyModel>    proxyModel;

};
