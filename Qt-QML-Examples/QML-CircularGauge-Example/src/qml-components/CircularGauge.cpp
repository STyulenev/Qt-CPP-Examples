#include "CircularGauge.h"

CircularGauge::CircularGauge(QQuickItem* parent) :
    QQuickPaintedItem(parent)
{
    majorTicks = 11.0;
    minorTicks = 4.0;
    gapAngle = 90;
    start_angle = 90 + gapAngle / 2;
    stop_angle = 360 - gapAngle;
    rot_deg = stop_angle / (majorTicks - 1);
    rot_rad = (rot_deg / 360.0) * 2 * M_PI;
    max = 100;
    min = 0;
    value = 0;
    step = max / (majorTicks - 1);
    digitFont = QFont("SansSerif", 10);
}

qreal CircularGauge::getValue() const
{
    return value;
}

void CircularGauge::paint(QPainter* painter)
{
    int side = qMin(width(), height());
    //    // Сохраняйте размер стороны четным, обрезая нечетные пиксели. //
    side &= ~0x01;

    //QRadialGradient gradient;
    QPen pen(Qt::black);
    pen.setWidth(1);

    // Initialize painter //
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(width() / 2, height() / 2);
    painter->scale(side / 256.0, side / 256.0);
    painter->setPen(pen);

    // Draw external circle //
    painter->setPen(pen);
    painter->setBrush(QColor(224, 224, 224));
    painter->drawEllipse(QPoint(0,0), 125, 125);

    // Draw inner shield //
    painter->setBrush(QColor(255, 255, 255));
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(QPoint(0,0), 115, 115);

    // точка в центре //
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawPoint(0, 0);

    int line = 10; // FIX #1 //

    // Метки //
    painter->save();
    painter->setBrush(Qt::black);
    painter->rotate(start_angle); // initial angle (first tick) //
    painter->setBrush(QBrush(Qt::black));
    qreal t_rot = stop_angle / (minorTicks * (majorTicks - 1) + majorTicks - 1);

    for (int i = 0; i < (minorTicks) * (majorTicks - 1) + majorTicks; i++) {
        if (minorTicks) {
            /*if (i % (int)(minorTicks + 1) == 0)
                painter->drawLine(QPoint(110, 0), QPoint(110 - line, 0));
            else*/
                painter->drawLine(QPoint(110, 0), (i % static_cast<int>(minorTicks + 1) == 0) ? QPoint(110 - line, 0) : QPoint(110 - line / 3, 0));
        } else {
            painter->drawLine(QPoint(110, 0), QPoint(110 - line, 0));
        }
        painter->rotate(t_rot);
    }

    painter->restore();

    // Draw scale numbers using vector rotation //
    // x' = xcos(a)-ysin(a)                     //
    // y' = xsin(a)-ycos(a)                     //
    painter->save();
    qreal rotation = (start_angle / 360) * 2 * M_PI;          // Initial rotation //
    painter->setFont(digitFont);
    for (int i = 0; i < majorTicks; i++) {
        QPointF point((70 * cos(rotation)), 70 * sin(rotation));                           // calculate digit coords      //
        QString value = QString::number(min + (qreal)i * step);
        QSize   size  = painter->fontMetrics().size(Qt::TextSingleLine, value);         // get string size in px       //
        point.rx() -= size.width() / 2;                                                  // center-align string (horiz) //
        point.ry() += size.height() / 4;                                                 // center-align string (vert)  //
        painter->drawText(point, value);
        rotation += rot_rad;
    }
    painter->restore();
    painter->save();

    // needle
    static const QPoint needle[5] = {
        QPoint(0, -3),
        QPoint(90, 0),
        QPoint(0, 3),
        QPoint(0, 5),
        QPoint(0, -5)
    };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->rotate(value2angle(currValue));
    painter->setBrush(Qt::red);
    painter->drawConvexPolygon(needle, 5);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPoint(0, 0), 5, 5);
    painter->restore();
}

void CircularGauge::setMajorTicks(int t)
{
    majorTicks = static_cast<qreal>(t);
    step = (max - min) / (majorTicks - 1);
    rot_deg = stop_angle / (majorTicks - 1);
    rot_rad = (rot_deg / 360.0) * 2 * M_PI;
    update();
}

int CircularGauge::getMajorTicks() const
{
    return static_cast<int>(majorTicks);
}

void CircularGauge::setMinorTicks(int t)
{
    minorTicks = static_cast<qreal>(t);
    update();
}

int CircularGauge::getMinorTicks() const
{
    return static_cast<int>(minorTicks);
}

void CircularGauge::setDigitFont(const QFont f)
{
    digitFont = f;
    update();
}

QFont CircularGauge::getDigitFont() const
{
    return digitFont;
}

void CircularGauge::setValue(qreal v)
{
    if (v > max)
        v = max;    // coerce

    if (v < min)
        v = min;

    currValue = value = v;

    update();
}

void CircularGauge::setRange(qreal mi, qreal ma)
{
    min  = mi;
    max  = ma;
    step = (max - min) / (majorTicks - 1);
    update();
}

void CircularGauge::setMinValue(const qreal mi)
{
    setRange(mi, max);
}

qreal CircularGauge::getMinValue() const
{
    return min;
}

void CircularGauge::setMaxValue(const qreal ma)
{
    setRange(min, ma);
}

qreal CircularGauge::getMaxValue() const
{
    return max;
}

void CircularGauge::setGapAngle(const qreal gap)
{
    gapAngle   = gap;
    start_angle = 90 + gapAngle / 2;
    stop_angle  = 360 - gapAngle;
    rot_deg = stop_angle/(majorTicks - 1);
    rot_rad = (rot_deg / 360.0) * 2 * M_PI;
    update();
}

qreal CircularGauge::getGapAngle() const
{
    return gapAngle;
}

qreal CircularGauge::value2angle(qreal val)
{
    qreal intervalLength = max - min;
    val = val - min;

    if (val > intervalLength)
        val = intervalLength;

    return start_angle + (val / intervalLength) * stop_angle;
}
