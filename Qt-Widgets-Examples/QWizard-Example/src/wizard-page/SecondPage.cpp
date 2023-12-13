#include "SecondPage.h"
#include "./ui_SecondPage.h"

namespace WizardPages {

SecondPage::SecondPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SecondPage)
{
    ui->setupUi(this);
    setTitle(tr("Second Page"));
    setSubTitle(tr("Second Page"));
}

SecondPage::~SecondPage()
{
    delete ui;
}

auto SecondPage::nextId() const -> int
{
    return 2;
}

} // namespace WizardPages
