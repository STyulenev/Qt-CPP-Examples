#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Tests {
    class Test_MainWindow;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class Tests::Test_MainWindow;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    auto on_pushButton_clicked() -> void;

private:
    Ui::MainWindow* ui;
    bool status = false;

};

} // namespace Views
