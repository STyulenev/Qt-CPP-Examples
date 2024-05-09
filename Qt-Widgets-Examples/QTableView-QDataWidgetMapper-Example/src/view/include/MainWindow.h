#pragma once

#include <QMainWindow>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class TableViewModel;
}

namespace View {

class EditForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_tableView_customContextMenuRequested(const QPoint& pos) -> void;

private:
    Ui::MainWindow* ui;

    ViewModels::TableViewModel* viewModel;
    EditForm* editForm;

};

} // namespace View
