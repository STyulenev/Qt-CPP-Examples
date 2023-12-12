#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_standartDialogButton_clicked() -> void;
    auto on_customDialogButton_clicked() -> void;
    auto on_standartPathDialogButton_clicked() -> void;
    auto on_standartColorDialogButton_clicked() -> void;
    auto on_standartFontDialog_clicked() -> void;
    auto on_standartProgressDialogButton_clicked() -> void;
    auto on_standartInputDialogButton_clicked() -> void;
    auto on_standartPrintDialogButton_clicked() -> void;

};

} // namespace Views
