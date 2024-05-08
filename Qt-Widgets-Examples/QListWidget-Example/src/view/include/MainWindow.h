#pragma once

#include <QMainWindow>

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
    auto addItemInListWidget(QString&& image, QString&& title, QString&& description) -> void;

private:
    Ui::MainWindow* ui;

};

} // namespace View
