#include "CustomHeaderView.h"

namespace Views {

CustomHeaderView::CustomHeaderView(Qt::Orientation orientation, QWidget* parent) :
    QHeaderView(orientation, parent)
{

}

auto CustomHeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const -> void
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if (logicalIndex == 3) {
        QStyleOptionButton option;
        option.rect = rect;
        option.rect.setX(rect.x() - rect.width()  + 20);


        option.state = QStyle::State_Enabled | QStyle::State_Active;

        if (allStatus) // or from model model()->headerData(logicalIndex, Qt::Horizontal, ... ).toBool()
            option.state |= QStyle::State_On;
        else
            option.state |= QStyle::State_Off;

        option.state |= QStyle::State_Off;

        style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
    }
}

auto CustomHeaderView::mousePressEvent(QMouseEvent* event) -> void
{
    int section = logicalIndexAt(event->pos());

    if (section == 3 && section < model()->columnCount()) {
        allStatus = !allStatus;
        model()->setHeaderData(section, Qt::Horizontal, QVariant(allStatus), Qt::UserRole);
    }

    QHeaderView::mousePressEvent(event);
    this->update();
}

} // namespace Views
