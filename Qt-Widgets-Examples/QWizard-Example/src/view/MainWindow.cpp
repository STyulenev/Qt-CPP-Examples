#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QWizard>
#include <WizardPages>

namespace Views {

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

auto MainWindow::on_questionnaireButton_clicked() -> void
{
    QWizard wizard;
    wizard.setWindowFlags(Qt::WindowContextHelpButtonHint);
    wizard.setWizardStyle(QWizard::ModernStyle); // or QWizard::ClassicStyle

    wizard.setPage(0, new WizardPages::FirstPage(&wizard));
    wizard.setPage(1, new WizardPages::SecondPage(&wizard));
    wizard.setPage(2, new WizardPages::ThirdPage(&wizard));
    wizard.setPage(3, new WizardPages::FinalPage(&wizard));

    wizard.setWindowTitle(tr("QWizard example"));
    wizard.show();

    if (wizard.exec()) {
        // result
    }
}

} // namespace Views
