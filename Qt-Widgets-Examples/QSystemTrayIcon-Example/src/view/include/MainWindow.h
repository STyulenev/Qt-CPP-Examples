#pragma once

#include <QMainWindow>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCloseEvent;

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    auto closeEvent(QCloseEvent* event) -> void;

private slots:
    auto iconActivated(QSystemTrayIcon::ActivationReason reason) -> void;

private:
    Ui::MainWindow* ui;
    QSystemTrayIcon* systemTray;

};

} // namespace Views
