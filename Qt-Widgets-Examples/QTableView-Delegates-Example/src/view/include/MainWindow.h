#pragma once

#include <QMainWindow>

namespace ViewModels {
    class TableViewModelForSimpleDelegates;
    class TableViewModelForStyledDelegates;
    class TableViewModelForCustomDelegates;
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;
    ViewModels::TableViewModelForSimpleDelegates* viewModelSimple;
    ViewModels::TableViewModelForStyledDelegates* viewModelStyled;
    ViewModels::TableViewModelForCustomDelegates* viewModelCustom;

public:
    explicit  MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

};

} // namespace Views
