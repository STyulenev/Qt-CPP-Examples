#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class TableModel;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    auto on_tableView_customContextMenuRequested(const QPoint& pos) -> void;

private:
    Ui::MainWindow* ui;
    ViewModels::TableModel* tableModel;

};

} // namespace Views
