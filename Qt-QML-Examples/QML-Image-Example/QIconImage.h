#pragma once

#include <QQuickPaintedItem>

class QIconImage : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit QIconImage(QQuickItem* parent = nullptr);
    virtual ~QIconImage();

    virtual void paint(QPainter* painter) override;

};
