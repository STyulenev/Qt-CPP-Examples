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
    auto on_pushButton_2_clicked() -> void;
    auto on_pushButton_3_clicked() -> void;
    auto on_pushButton_4_clicked() -> void;

private:
    Ui::MainWindow* ui;

};
