#include "WidgetWithTwoRadioButtons.h"
#include "ui_WidgetWithTwoRadioButtons.h"

WidgetWithTwoRadioButtons::WidgetWithTwoRadioButtons(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::WidgetWithTwoRadioButtons)
{
    ui->setupUi(this);
}

WidgetWithTwoRadioButtons::~WidgetWithTwoRadioButtons()
{
    delete ui;
}

auto WidgetWithTwoRadioButtons::getStatus() const -> bool
{
    return ui->radioButton->isChecked();
}

auto WidgetWithTwoRadioButtons::setStatus(bool status) -> void
{
    ui->radioButton->setChecked(status);
    ui->radioButton_2->setChecked(!status);
}
