#include "WidgetWithTwoRadioButtons.h"
#include "ui_WidgetWithTwoRadioButtons.h"

WidgetWithTwoRadioButtons::WidgetWithTwoRadioButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetWithTwoRadioButtons)
{
    ui->setupUi(this);
}

WidgetWithTwoRadioButtons::~WidgetWithTwoRadioButtons()
{
    delete ui;
}

auto WidgetWithTwoRadioButtons::getStatus() -> bool
{
    return ui->radioButton->isChecked();
}

auto WidgetWithTwoRadioButtons::setStatus(bool status) -> void
{
    if (status) {
        ui->radioButton->setChecked(true);
        ui->radioButton_2->setChecked(false);
    } else {
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(true);
    }
}
