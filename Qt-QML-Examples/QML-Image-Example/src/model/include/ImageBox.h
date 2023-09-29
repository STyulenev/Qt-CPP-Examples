#pragma once

#include <QQuickPaintedItem>

class ImageBox : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit ImageBox(QQuickItem* parent = nullptr);
    virtual ~ImageBox();

    virtual void paint(QPainter* painter) override;

};
