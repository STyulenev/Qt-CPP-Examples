#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Models {
    class TableViewModel;
    class QComboBoxModel;
}

class QDataWidgetMapper;

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    auto on_tableView_doubleClicked(const QModelIndex& index) -> void;

private:
    Ui::MainWindow* ui;

    Models::QComboBoxModel* model;
    Models::TableViewModel* tableModel;
    QDataWidgetMapper*      mapper;

};

} // namespace Views
