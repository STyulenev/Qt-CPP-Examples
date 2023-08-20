#include "QIconImage.h"

#include <QPainter>
#include <QDebug>

QIconImage::QIconImage(QQuickItem* parent) :
    QQuickPaintedItem(parent)
{

}

QIconImage::~QIconImage()
{

}

void QIconImage::paint(QPainter* painter)
{
   // m_icon.paint(painter, 0, 0, 100, 100/*int(width()), int(height())*/);
    //painter(":/grid.png");

    //painter->fillRect(0, 0, 100, 100, QColor("grey").rgba());

    QPixmap image(":/grid.png");
    painter->drawPixmap(0, 0, 100, 100, image);
            //(&image);

    /*QBrush brush(QColor("#007430"));

        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing);

        QSizeF itemSize = size();
        painter->drawRoundedRect(0, 0, itemSize.width(), itemSize.height() - 10, 10, 10);

        if (true)
        {
            const QPointF points[3] = {
                QPointF(itemSize.width() - 10.0, itemSize.height() - 10.0),
                QPointF(itemSize.width() - 20.0, itemSize.height()),
                QPointF(itemSize.width() - 30.0, itemSize.height() - 10.0),
            };
            painter->drawConvexPolygon(points, 3);
        }
        else
        {
            const QPointF points[3] = {
                QPointF(10.0, itemSize.height() - 10.0),
                QPointF(20.0, itemSize.height()),
                QPointF(30.0, itemSize.height() - 10.0),
            };
            painter->drawConvexPolygon(points, 3);

        }*/
}
