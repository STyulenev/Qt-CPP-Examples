#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace ViewModels {
    class TableViewModel;
}

namespace ProxyModels {
    class ProxyTableViewModel;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;
    ViewModels::TableViewModel*       viewModel;
    ProxyModels::ProxyTableViewModel* proxyModel;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_tableView_customContextMenuRequested(const QPoint& pos) -> void;

};

} // namespace Views
