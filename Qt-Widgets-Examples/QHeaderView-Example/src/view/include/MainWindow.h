#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class TableViewModel;
}


namespace Views {

class CustomHeaderView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    ViewModels::TableViewModel* viewModel;
    Views::CustomHeaderView* header;

};

} // namespace Views
