#include "ImageProvider.h"

ImageProvider::ImageProvider() :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

ImageProvider::~ImageProvider()
{

}

QPixmap ImageProvider::requestPixmap(const QString& id, QSize* size, const QSize& requestedSize)
{
    int width = 100;
    int height = 50;

    if (size)
        *size = QSize(width, height);

    //QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width, requestedSize.height() > 0 ? requestedSize.height() : height);

    QPixmap pixmap(":/grid.png");
    //pixmap.fill(QColor("grey").rgba());
    //pixmap.
    return pixmap;
}
