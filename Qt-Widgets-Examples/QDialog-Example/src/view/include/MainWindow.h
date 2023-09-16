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

public slots:
    auto on_pushButton_clicked() -> void;

};

} // namespace Views
