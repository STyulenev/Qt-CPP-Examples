#pragma once

#include <QMainWindow>
#include <TableViewModel.h>

#include "editform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    std::shared_ptr<TableViewModel> viewModel;
    std::shared_ptr<EditForm> editForm;

private slots:
    auto on_tableView_clicked(const QModelIndex& index) -> void;

};

