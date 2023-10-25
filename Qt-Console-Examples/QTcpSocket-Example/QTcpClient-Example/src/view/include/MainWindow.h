#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace Transport {
    class TcpSocket;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    virtual ~MainWindow();

private slots:
    auto on_pushButton_clicked() -> void;

private:
    Ui::MainWindow* ui;
    Transport::TcpSocket* socket;

};

} // namespace Views
