#pragma once

#include <QMainWindow>
#include "HTTPClient.h"

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
    auto on_pushButton_clicked() -> void;

private:
    Ui::MainWindow* ui;

};
