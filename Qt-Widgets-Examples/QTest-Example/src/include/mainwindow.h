#pragma once

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class Test_MainWindow;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;

    std::shared_ptr<QRegularExpressionValidator> nameValidator;
    std::shared_ptr<QRegularExpressionValidator> ipAddressValidator;
    std::shared_ptr<QRegularExpressionValidator> emailValidator;

    bool status = false;

};

