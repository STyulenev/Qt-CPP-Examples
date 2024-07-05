#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "SQLHighlighter.h"

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(16);

    ui->textEdit->setFont(font);

    highlighter = new WidgetControlles::SQLHighlighter(ui->textEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
