#include "CircularGauge.h"

#include <math.h>

CircularGauge::CircularGauge(QQuickItem* parent) :
    QQuickPaintedItem(parent)
{
    m_majorTicks = 11;
    m_minorTicks = 4;
    m_gapAngle = 90;
    startAngle = 90 + m_gapAngle / 2;
    stopAngle = 360 - m_gapAngle;
    rotationDegree = stopAngle / (m_majorTicks - 1);
    rotationRadian = (rotationDegree / 360.0) * 2 * M_PI;
    m_max = 100;
    m_min = 0;
    m_value = 0;
    step = m_max / (m_majorTicks - 1);
    m_font = QFont("SansSerif", 10);
}

qreal CircularGauge::getMinValue() const
{
    return m_min;
}

qreal CircularGauge::getMaxValue() const
{
    return m_max;
}

qreal CircularGauge::getValue() const
{
    return m_value;
}

qreal CircularGauge::getGapAngle() const
{
    return m_gapAngle;
}

int CircularGauge::getMajorTicks() const
{
    return m_majorTicks;
}

int CircularGauge::getMinorTicks() const
{
    return m_minorTicks;
}

const QFont& CircularGauge::getFont() const
{
    return m_font;
}

void CircularGauge::setMinValue(const qreal min)
{
    setRange(min, m_max);

    emit minChanged();
}

void CircularGauge::setMaxValue(const qreal max)
{
    setRange(m_min, max);

    emit maxChanged();
}


void CircularGauge::setValue(qreal value)
{
    m_value = (value > m_max) ? m_max : (value < m_min) ? m_min : value;

    update();

    emit valueChanged();
}

void CircularGauge::setGapAngle(const qreal gap)
{
    m_gapAngle   = gap;
    startAngle = 90 + m_gapAngle / 2;
    stopAngle  = 360 - m_gapAngle;
    rotationDegree = stopAngle/(m_majorTicks - 1);
    rotationRadian = (rotationDegree / 360.0) * 2 * M_PI;
    update();

    emit gapAngleChanged();
}

void CircularGauge::setMajorTicks(int majorTicks)
{
    m_majorTicks = majorTicks;
    step = (m_max - m_min) / (m_majorTicks - 1);
    rotationDegree = stopAngle / (m_majorTicks - 1);
    rotationRadian = (rotationDegree / 360.0) * 2 * M_PI;
    update();

    emit majorTicksChanged();
}

void CircularGauge::setMinorTicks(int minorTicks)
{
    m_minorTicks = minorTicks;
    update();

    emit minorTicksChanged();
}

void CircularGauge::setFont(const QFont& font)
{
    m_font = font;
    update();

    emit fontChanged();
}

void CircularGauge::paint(QPainter* painter)
{
    int side = qMin(width(), height());
    side &= ~0x01;

    QPen pen(Qt::black);
    pen.setWidth(1);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(width() / 2, height() / 2);
    painter->scale(side / 256.0, side / 256.0);
    painter->setPen(pen);

    // Внешний круг
    painter->setPen(pen);
    painter->setBrush(QColor(224, 224, 224));
    painter->drawEllipse(QPoint(0,0), 125, 125);

    // Внутренняя рамка
    painter->setBrush(QColor(255, 255, 255));
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(QPoint(0,0), 115, 115);

    // Точка в центре
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawPoint(0, 0);

    int line = 10;

    // Метки
    painter->save();
    painter->rotate(startAngle);
    painter->setBrush(QBrush(Qt::black));
    qreal t_rot = stopAngle / (m_minorTicks * (m_majorTicks - 1) + m_majorTicks - 1);

    for (int i = 0; i < (m_minorTicks) * (m_majorTicks - 1) + m_majorTicks; i++) {
        if (m_minorTicks)
            painter->drawLine(QPoint(110, 0), (i % (m_minorTicks + 1) == 0) ? QPoint(110 - line, 0) : QPoint(110 - line / 3, 0));
        else
            painter->drawLine(QPoint(110, 0), QPoint(110 - line, 0));

        painter->rotate(t_rot);
    }

    painter->restore();

    // Значения км/ч на метках
    painter->save();
    qreal rotation = (startAngle / 360) * 2 * M_PI;
    painter->setFont(m_font);
    for (int i = 0; i < m_majorTicks; i++) {
        QPointF point((70 * cos(rotation)), 70 * sin(rotation));
        QString value = QString::number(m_min + (qreal)i * step);
        QSize   size  = painter->fontMetrics().size(Qt::TextSingleLine, value);
        point.rx() -= size.width() / 2;
        point.ry() += size.height() / 4;
        painter->drawText(point, value);
        rotation += rotationRadian;
    }
    painter->restore();
    painter->save();

    // Стрелка
    static const QPoint needle[5] = {
        QPoint(0, -3),
        QPoint(90, 0),
        QPoint(0, 3),
        QPoint(0, 5),
        QPoint(0, -5)
    };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->rotate(convertValueToAngle(m_value));
    painter->setBrush(Qt::red);
    painter->drawConvexPolygon(needle, 5);

    // Круг в центре
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPoint(0, 0), 5, 5);
    painter->restore();
}

void CircularGauge::setRange(const qreal min, const qreal max)
{
    m_min = min;
    m_max = max;
    step = (m_max - m_min) / (m_majorTicks - 1);
    update();
}

qreal CircularGauge::convertValueToAngle(qreal val)
{
    qreal intervalLength = m_max - m_min;
    val = val - m_min;

    if (val > intervalLength)
        val = intervalLength;

    return startAngle + (val / intervalLength) * stopAngle;
}
