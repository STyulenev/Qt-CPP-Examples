#include "FinalPage.h"
#include "./ui_FinalPage.h"

namespace WizardPages {

FinalPage::FinalPage(QWidget* parent) :
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

auto FinalPage::initializePage() -> void
{
    const QString data = QString("Name: %1\nSex: %2\nAge: %3")
                             .arg(field("name").toString())
                             .arg(field("sex").toBool() ? "Male" : "Female")
                             .arg(field("age").toInt());

    ui->textEdit->append(data);
}

} // namespace WizardPages
