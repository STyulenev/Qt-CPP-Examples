#pragma once

#include <QtQuick/QQuickPaintedItem>
#include <QPainter>

class CircularGauge : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal min   READ getMinValue WRITE setMinValue NOTIFY minChanged)
    Q_PROPERTY(qreal max   READ getMaxValue WRITE setMaxValue NOTIFY maxChanged)
    Q_PROPERTY(qreal value READ getValue    WRITE setValue    NOTIFY valueChanged)
    /*Q_PROPERTY(qreal    gapAngle   READ getGapAngle    WRITE setGapAngle NOTIFY minValueChanged)
    Q_PROPERTY(int      majorTicks  READ getMajorTicks  WRITE setMajorTicks NOTIFY minValueChanged)
    Q_PROPERTY(int      minorTicks  READ getMinorTicks  WRITE setMinorTicks NOTIFY minValueChanged)
    Q_PROPERTY(QFont    digitFont   READ getDigitFont   WRITE setDigitFont NOTIFY minValueChanged) */

public:
    explicit CircularGauge(QQuickItem* parent = 0);
    ~CircularGauge() = default;

    void setMinValue(const qreal min);
    void setMaxValue(const qreal max);
    void setValue(qreal value);
    void setGapAngle(const qreal gap);
    void setMajorTicks(const int ticks);
    void setMinorTicks(const int ticks);
    void setDigitFont(const QFont font);

    qreal getMinValue() const;
    qreal getMaxValue() const;
    qreal getValue() const;
    qreal getGapAngle() const;
    int getMajorTicks() const;
    int getMinorTicks() const;
    QFont getDigitFont() const;

    void paint(QPainter* painter) override;

private:
    void setRange(qreal min, qreal max);
    qreal value2angle(qreal value);

signals:
    void minChanged();
    void maxChanged();
    void valueChanged();

private:
    qreal max;              // max indicator value (final on scale)
    qreal min;              // min indicator value (first on scale)
    qreal step;             // scale tick step
    qreal value;            // target indicator value
    qreal currValue;        // current value (needle position during animation)
    qreal majorTicks;       // Number of major scale ticks
    qreal minorTicks;       // Number of mainor scale ticks
    qreal rot_deg;
    qreal rot_rad; // Scale number rotation step (deg & radians)
    qreal start_angle;
    qreal stop_angle;
    qreal gapAngle;
    QFont digitFont;

};
