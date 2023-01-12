#include "ColorEditor.h"
#include "ui_ColorEditor.h"

#include <QColorDialog>

ColorEditor::ColorEditor(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::ColorEditor)
{
    ui->setupUi(this);
}

ColorEditor::~ColorEditor()
{
    delete ui;
}

auto ColorEditor::getColor() -> QString
{
    return color.name();
}

auto ColorEditor::setColor(QString& color) -> void
{
    this->color = QColor(color);
    updateColor();
}

auto ColorEditor::on_pushButton_clicked() -> void
{
    std::shared_ptr<QColorDialog> colorDialog = std::make_shared<QColorDialog>(this);
    colorDialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::ShowAlphaChannel);

    QColor currentColor = colorDialog->currentColor();
    currentColor.setAlpha(255);
    colorDialog->setCurrentColor(currentColor);

    if (colorDialog->exec() == QColorDialog::Accepted) {
        color = colorDialog->currentColor();
        updateColor();
    }
}

auto ColorEditor::updateColor() -> void
{
    QString colorName = this->color.name();
    ui->label->setStyleSheet("background-color: " + colorName);
    ui->label->setText(colorName);
}
