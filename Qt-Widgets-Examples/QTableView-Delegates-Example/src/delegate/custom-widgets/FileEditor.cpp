#include "FileEditor.h"
#include "ui_FileEditor.h"

#include <QFileDialog>

FileEditor::FileEditor(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::FileEditor)
{
    ui->setupUi(this);
}

FileEditor::~FileEditor()
{
    delete ui;
}

auto FileEditor::getImage() -> QByteArray&
{
    return image;
}

auto FileEditor::setImage(QByteArray& newImage) -> void
{
    image = std::move(newImage);
    updateImage();
}

auto FileEditor::on_pushButton_clicked() -> void
{
    QString path = QFileDialog::getOpenFileName(this, tr("Выберите картинку"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        // error
        return;
    }

    image = file.readAll();
    file.close();

    updateImage();
}

auto FileEditor::updateImage() -> void
{
    QPixmap outPixmap;
    outPixmap.loadFromData(image);
    ui->label->setPixmap(outPixmap.scaled(32, 32));
}

