#include "MyRectangle.h"

#include <QBrush>
#include <QPen>
#include <QMouseEvent>

MyRectangle::MyRectangle(QQuickItem* parent) :
    QQuickPaintedItem(parent),
    m_color(Qt::blue)
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

auto MyRectangle::paint(QPainter* painter) -> void
{
    QBrush brush(m_color);

    painter->setPen(Qt::NoPen);
    painter->setRenderHints(QPainter::Antialiasing, true);

    painter->setBrush(brush);
    painter->drawRect(0, 0, painter->window().width(), painter->window().height());
}

auto MyRectangle::getColor() const -> const QColor&
{
    return m_color;
}

auto MyRectangle::setColor(const QColor& color) -> void
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged();
}

auto MyRectangle::mousePressEvent(QMouseEvent* event) -> void
{
    if (event->button() == Qt::LeftButton) {
        m_color = (m_color == Qt::blue) ? Qt::red : Qt::blue;
        emit colorChanged();
        update();
    }
}
