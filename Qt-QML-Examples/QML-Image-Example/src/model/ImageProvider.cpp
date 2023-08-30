#include "ImageProvider.h"

ImageProvider::ImageProvider() :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

ImageProvider::~ImageProvider()
{

}

QPixmap ImageProvider::requestPixmap([[maybe_unused]] const QString& id, QSize* size, [[maybe_unused]] const QSize& requestedSize)
{
    const int width = 32;
    const int height = 32;

    if (size)
        *size = QSize(width, height);

    QPixmap pixmap(":/res/grid.png");

    return pixmap;
}
