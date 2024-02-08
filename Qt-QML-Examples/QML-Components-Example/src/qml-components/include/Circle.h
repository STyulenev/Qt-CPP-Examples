#pragma once

#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>

class QMouseEvent;

class Circle : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)

public:
    explicit Circle(QQuickItem* parent = 0);
    ~Circle() = default;

    auto paint(QPainter* painter) -> void override;

    auto getColor() const -> const QColor&;
    auto setColor(const QColor& color) -> void;

protected:
    auto mousePressEvent(QMouseEvent* event) -> void override;

signals:
    auto colorChanged() -> void;

private:
    QColor m_color;

};
