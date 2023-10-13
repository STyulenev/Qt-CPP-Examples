#pragma once

#include <QtGui>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT ToleranceBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value    READ getValue    WRITE setValue)
    Q_PROPERTY(int quantity READ getQuantity WRITE setQuantity)

private:
    int m_value;
    int m_quantity;
    float WR;
    float HR;
    bool Mpressed;
    int painterWidth;
    int painterHeight;

public:
    explicit ToleranceBar(QWidget* parent = 0);
    virtual ~ToleranceBar() = default;
    
    int getValue() const;
    int getQuantity() const;

    void setValue(const int m_value);
    void setQuantity(const int m_quantity);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

};

