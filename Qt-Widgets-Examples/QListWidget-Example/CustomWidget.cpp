#include "CustomWidget.h"
#include "ui_CustomWidget.h"

CustomWidget::CustomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidget)
{
    ui->setupUi(this);

    ui->title->setStyleSheet("font-size: 14px;"
                             "font-family: Verdana, Arial, Helvetica, sans-serif;"
                             "font-weight: bold;"
                             "color: black;"
                             //"background-color: #99FFFF;"
                             "border: 2px solid black;"
                             );

    ui->description->setStyleSheet("text-align: justify");
}

CustomWidget::~CustomWidget()
{
    delete ui;
}

auto CustomWidget::setImage(const QString&& icon) -> void
{
    QPixmap outPixmap(icon);
    ui->image->setPixmap(outPixmap.scaled(128, 128));
}

auto CustomWidget::setTitle(const QString&& title) -> void
{
    ui->title->setText(title);
}

auto CustomWidget::setDescription(const QString&& description) -> void
{
    ui->description->setText(description);
}
