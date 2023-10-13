#include "ToleranceBar.h"

ToleranceBar::ToleranceBar(QWidget* parent) :
    QWidget(parent)
{
    m_value = 0;
    m_quantity = 10;
    painterWidth = 510;
    painterHeight = 150;
    WR = (this->width() * 1.0) / painterWidth;
    HR = (this->height() * 1.0) / painterHeight;
    Mpressed = false;
}

int ToleranceBar::getValue() const
{
    return m_value;
}

void ToleranceBar::setValue(const int value)
{
    this->m_value = value;
}

int ToleranceBar::getQuantity() const
{
    return m_quantity;
}

void ToleranceBar::setQuantity(const int quantity)
{
    this->m_quantity = quantity;
}

void ToleranceBar::mousePressEvent(QMouseEvent* event)
{
    WR = (this->width() * 1.0) / painterWidth;
    HR = (this->height() * 1.0) / painterHeight;

    float x = event->x() / WR, y = event->y() / HR;

    if (event->button() == Qt::LeftButton) {
        float p = ((painterHeight - 10) * ((painterWidth - 10) - x) / (painterWidth - 10));
        if (y > (p) && y < (painterHeight - 10) && x < (painterWidth - 10)) {
            m_value = ((x * m_quantity) / (painterWidth - 10)) + 1;
            Mpressed = true;
            update();
        } else if (y < p) { // чтобы было 0
            m_value = 0;
            update();
        }
    }
}

void ToleranceBar::mouseMoveEvent(QMouseEvent* event)
{
    WR = (this->width() * 1.0) / painterWidth;
    HR = (this->height() * 1.0) / painterHeight;

    float x = event->x() / WR, y = event->y() / HR;

    if (Mpressed) {
        float p = ((painterHeight - 10) * ((painterWidth - 10) - x) / (painterWidth - 10));
        if(y > (p) && y < (painterHeight - 10) && x < (painterWidth - 10)) {
            m_value = ((x * m_quantity) / (painterWidth - 10)) + 1;
            update();
        } else if (y < p) { // чтобы было 0
            m_value = 0;
            update();
        }
    }
}

void ToleranceBar::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event)

    Mpressed = false;
}

void ToleranceBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setWindow(0, 0, painterWidth, painterHeight);
    painter.setRenderHint(QPainter::Antialiasing);

    QPolygon polygonOne, polygonTwo;
    polygonOne << QPoint(0, painterHeight - 10)
               << QPoint((painterWidth - 10), painterHeight - 10)
               << QPoint((painterWidth - 10), 0);

    painter.setBrush(QColor(40, 40, 40));
    painter.setPen(QPen(Qt::black, 5));
    painter.drawPolygon(polygonOne);

    polygonTwo << QPoint(0, painterHeight - 10)
               << QPoint((painterWidth - 10) * m_value / m_quantity, painterHeight - 10)
               << QPoint((painterWidth - 10) * m_value / m_quantity, ((painterHeight - 10) * (m_quantity - m_value) / m_quantity)) ;

    QLinearGradient linGrad(0, 50,(painterWidth - 10), 50);
    linGrad.setColorAt(0, Qt::green);
    linGrad.setColorAt(0.5, Qt::yellow);
    linGrad.setColorAt(1, Qt::red);
    linGrad.setSpread(QGradient::PadSpread);
    painter.setPen(QPen(Qt::black, 5));
    painter.setBrush(linGrad);
    painter.drawPolygon(polygonTwo);
    painter.setBrush(QColor(40, 40, 40));
    painter.setPen(QPen(Qt::black, 5));

    for (int count = 1; count < m_quantity; count++) {
        painter.setPen(QPen(Qt::black, 5));
        painter.drawLine((painterWidth - 10) * count / m_quantity,
                         (painterHeight + 1 - 10) * (m_quantity-count) / m_quantity,
                         (painterWidth - 10) * count / m_quantity,
                         (painterHeight - 10));
        painter.setPen(QPen(Qt::red, 5));
    }
}
