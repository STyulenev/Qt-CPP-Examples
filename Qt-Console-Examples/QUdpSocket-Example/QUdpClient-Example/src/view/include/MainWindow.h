#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace Transport {
    class UdpSocket;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    virtual ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    Transport::UdpSocket* socket;

};

} // namespace Views
