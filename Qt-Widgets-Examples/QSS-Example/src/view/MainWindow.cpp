#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

namespace View {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_exitButton_clicked() -> void
{
    QMessageBox questionBox;
    questionBox.setText("Exit");
    questionBox.setInformativeText("Do you want to exit the application?");
    questionBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    questionBox.setWindowFlags(Qt::FramelessWindowHint);

    if (questionBox.exec()) {
        exit(0);
    }
}

} // namespace View
