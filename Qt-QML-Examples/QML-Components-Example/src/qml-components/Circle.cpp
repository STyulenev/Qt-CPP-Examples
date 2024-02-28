#include "Circle.h"

#include <QBrush>
#include <QPen>
#include <QMouseEvent>

Circle::Circle(QQuickItem* parent) :
    QQuickPaintedItem(parent),
    m_color(Qt::blue)
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

auto Circle::paint(QPainter* painter) -> void
{
    QBrush brush(m_color);

    painter->setPen(Qt::NoPen);
    painter->setRenderHints(QPainter::Antialiasing, true);

    painter->setBrush(brush);
    painter->drawEllipse(this->boundingRect());
}

auto Circle::getColor() const -> const QColor&
{
    return m_color;
}

auto Circle::setColor(const QColor& color) -> void
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged();
}

auto Circle::mousePressEvent(QMouseEvent* event) -> void
{
    if (event->button() == Qt::LeftButton) {
        m_color = (m_color == Qt::blue) ? Qt::red : Qt::blue;
        emit colorChanged();
        update();
    }
}
