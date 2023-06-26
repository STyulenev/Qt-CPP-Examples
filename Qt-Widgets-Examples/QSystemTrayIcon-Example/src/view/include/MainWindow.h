#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    auto closeEvent(QCloseEvent* event) -> void;

private slots:
    auto iconActivated(QSystemTrayIcon::ActivationReason reason) -> void;

private:
    Ui::MainWindow* ui;
    QSystemTrayIcon* systemTray;
};
