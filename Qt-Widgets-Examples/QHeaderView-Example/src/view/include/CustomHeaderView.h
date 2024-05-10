#pragma once

#include <QDebug>

#include <QHeaderView>
#include <QPainter>
#include <QMouseEvent>

namespace Views {

class CustomHeaderView : public QHeaderView
{

public:
    CustomHeaderView(Qt::Orientation orientation, QWidget* parent = 0);
    ~CustomHeaderView() = default;

    auto paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const -> void override;
    auto mousePressEvent(QMouseEvent* event) -> void override;

private:
    bool allStatus = false;

};

} // namespace Views
