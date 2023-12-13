#include "FirstPage.h"
#include "./ui_FirstPage.h"

namespace WizardPages {

FirstPage::FirstPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::FirstPage)
{
    ui->setupUi(this);
    setTitle(tr("First Page"));
    setSubTitle(tr("First Page"));
}

FirstPage::~FirstPage()
{
    delete ui;
}

auto FirstPage::nextId() const -> int
{
    return 1;
}

} // namespace WizardPages
