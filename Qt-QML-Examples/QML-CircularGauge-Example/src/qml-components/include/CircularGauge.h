#pragma once

#include <QPainter>
#include <QtQuick/QQuickPaintedItem>

class CircularGauge : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal min        READ getMinValue   WRITE setMinValue   NOTIFY minChanged)
    Q_PROPERTY(qreal max        READ getMaxValue   WRITE setMaxValue   NOTIFY maxChanged)
    Q_PROPERTY(qreal value      READ getValue      WRITE setValue      NOTIFY valueChanged)
    Q_PROPERTY(qreal gapAngle   READ getGapAngle   WRITE setGapAngle   NOTIFY gapAngleChanged)
    Q_PROPERTY(int   majorTicks READ getMajorTicks WRITE setMajorTicks NOTIFY majorTicksChanged)
    Q_PROPERTY(int   minorTicks READ getMinorTicks WRITE setMinorTicks NOTIFY minorTicksChanged)
    Q_PROPERTY(QFont font       READ getFont       WRITE setFont       NOTIFY fontChanged)

public:
    explicit CircularGauge(QQuickItem* parent = 0);
    ~CircularGauge() = default;

    qreal getMinValue() const;
    qreal getMaxValue() const;
    qreal getValue() const;
    qreal getGapAngle() const;
    int getMajorTicks() const;
    int getMinorTicks() const;
    const QFont& getFont() const;

    void setMinValue(const qreal min);
    void setMaxValue(const qreal max);
    void setValue(qreal value);
    void setGapAngle(const qreal gap);
    void setMajorTicks(const int ticks);
    void setMinorTicks(const int ticks);
    void setFont(const QFont& font);

    void paint(QPainter* painter) override;

private:
    void setRange(const qreal min, const qreal max);
    qreal convertValueToAngle(qreal value);

signals:
    void minChanged();
    void maxChanged();
    void valueChanged();
    void gapAngleChanged();
    void majorTicksChanged();
    void minorTicksChanged();
    void fontChanged();

private:
    qreal m_min;
    qreal m_max;
    qreal m_value;
    qreal m_gapAngle;
    int m_majorTicks;
    int m_minorTicks;
    QFont m_font;

    qreal step;
    qreal rotationDegree;
    qreal rotationRadian;
    qreal startAngle;
    qreal stopAngle;

};
