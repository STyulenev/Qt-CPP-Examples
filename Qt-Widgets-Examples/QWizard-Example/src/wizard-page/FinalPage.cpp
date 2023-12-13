#include "FinalPage.h"
#include "./ui_FinalPage.h"

namespace WizardPages {

FinalPage::FinalPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::FinalPage)
{
    ui->setupUi(this);
    setTitle(tr("Final Page"));
    setSubTitle(tr("Final Page"));
}

FinalPage::~FinalPage()
{
    delete ui;
}

} // namespace WizardPages
