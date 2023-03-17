#pragma once

#include <QMainWindow>
#include <QDataWidgetMapper>

#include <TableViewModel.h>

#include "QComboBoxModel.h"
#include "QComboBoxDelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    auto on_tableView_doubleClicked(const QModelIndex& index) -> void;

private:
    Ui::MainWindow* ui;

    std::shared_ptr<Models::QComboBoxModel> model;
    std::shared_ptr<Models::TableViewModel> tableModel;
    std::shared_ptr<QDataWidgetMapper>      mapper;
};
