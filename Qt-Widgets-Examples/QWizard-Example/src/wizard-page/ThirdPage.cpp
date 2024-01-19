#include "ThirdPage.h"
#include "./ui_ThirdPage.h"

namespace WizardPages {

ThirdPage::ThirdPage(QWidget* parent) :
    QWizardPage(parent),
    ui(new Ui::ThirdPage)
{
    ui->setupUi(this);
    setTitle(tr("Third Page"));
    setSubTitle(tr("Third Page"));

    registerField("age", ui->ageSpinBox);
}

ThirdPage::~ThirdPage()
{
    delete ui;
}

auto ThirdPage::nextId() const -> int
{
    return 3;
}

} // namespace WizardPages
