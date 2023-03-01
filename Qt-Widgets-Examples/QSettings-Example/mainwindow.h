#pragma once

#include <QMainWindow>
#include "Setting.h"

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
    auto on_saveButton_clicked() -> void;

private:
    Ui::MainWindow* ui;
};

