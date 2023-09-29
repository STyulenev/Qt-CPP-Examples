#include "ImageBox.h"

#include <QPainter>

ImageBox::ImageBox(QQuickItem* parent) :
    QQuickPaintedItem(parent)
{

}

ImageBox::~ImageBox()
{

}

void ImageBox::paint(QPainter* painter)
{
    QPixmap image(":/res/grid.png");
    painter->drawPixmap(0, 0, 32, 32, image);
}
