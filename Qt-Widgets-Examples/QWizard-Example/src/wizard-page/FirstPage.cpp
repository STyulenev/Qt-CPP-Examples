#include "FirstPage.h"
#include "./ui_FirstPage.h"

namespace WizardPages {

FirstPage::FirstPage(QWidget* parent) :
    QWizardPage(parent),
    ui(new Ui::FirstPage)
{
    ui->setupUi(this);
    setTitle(tr("First Page"));
    setSubTitle(tr("First Page"));

    registerField("name", ui->nameLineEdit);
}

FirstPage::~FirstPage()
{
    delete ui;
}

auto FirstPage::nextId() const -> int
{
    return 1;
}

auto FirstPage::validatePage() -> bool
{
    return !ui->nameLineEdit->text().isEmpty();
}

} // namespace WizardPages
