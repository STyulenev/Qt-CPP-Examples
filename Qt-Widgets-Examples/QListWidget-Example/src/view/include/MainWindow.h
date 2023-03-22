#pragma once

#include <QMainWindow>

#include "CustomWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    auto addItemInListWidget(QString&& image, QString&& title, QString&& description) -> void;
};

} // namespace View
