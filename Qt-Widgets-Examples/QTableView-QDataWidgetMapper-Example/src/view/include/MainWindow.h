#pragma once

#include <QMainWindow>
#include <QMenu>

#include "TableViewModel.h"
#include "EditForm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    std::shared_ptr<ViewModels::TableViewModel> viewModel;
    std::shared_ptr<EditForm> editForm;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_tableView_customContextMenuRequested(const QPoint& pos) -> void;

};

} // namespace View
