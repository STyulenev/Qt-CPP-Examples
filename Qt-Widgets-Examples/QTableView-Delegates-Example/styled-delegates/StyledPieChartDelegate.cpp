#include "StyledPieChartDelegate.h"

#include <QPainter>

namespace StyledDelegates {

StyledPieChartDelegate::StyledPieChartDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{

}

auto StyledPieChartDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize
{
    return QSize(64, 64);
}

auto StyledPieChartDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    return nullptr;
}

auto StyledPieChartDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    //painter->save();
    QRect rect(option.rect);

    double first = 30;
    double second = 20;
    double third = 10;
    double fourth = 40;
    double sum = first + second + third + fourth;

    QRectF size = rect.toRectF();
    const int diametr = 64; //rect.height() * 0.8;
    const int centerX = rect.x() + rect.width()  / 2; // rect.width()
    const int centerY = rect.y() + rect.height() / 2; //rect.height()

    { // обводка
        size.setX(centerX - rect.width() / 4 - (diametr / 2) - 1);
        size.setY(centerY - (diametr / 2) - 1);
        size.setHeight(diametr + 2);
        size.setWidth(diametr + 2);

        painter->setBrush(Qt::black);
        painter->drawPie(size, 0, 360 * 16);
    }

    { // Рисование PieChart
        size.setX(centerX - rect.width() / 4 - (diametr / 2));
        size.setY(centerY - (diametr / 2));
        size.setHeight(diametr);
        size.setWidth(diametr);

        //painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::red);
        painter->drawPie(size, 0, 360 * 16 * first/sum);
        painter->setBrush(Qt::blue);
        painter->drawPie(size, 360 * 16 * first/sum, 360 * 16 * second/sum);
        painter->setBrush(Qt::yellow);
        painter->drawPie(size, 360 * 16 - 360 * 16 * third/sum - 360 * 16 * fourth/sum, 360 * 16 * third/sum);
        painter->setBrush(Qt::green);
        painter->drawPie(size, 360 * 16 - 360 * 16 * fourth/sum, 360 * 16 * fourth/sum);
    }

    { // Рисование легенды
        painter->fillRect(rect.x() + rect.width() / 2, rect.y() + 10, 10, 10, Qt::red);
        painter->drawText(rect.x() + rect.width() / 2, rect.y() + 8, 50, 10, Qt::AlignCenter, " - text");
        painter->fillRect(rect.x() + rect.width() / 2, rect.y() + 30, 10, 10, Qt::blue);
        painter->drawText(rect.x() + rect.width() / 2, rect.y() + 28, 50, 10, Qt::AlignCenter, " - text");

        painter->fillRect(rect.x() + 3 * rect.width() / 4, rect.y() + 10, 10, 10, Qt::yellow);
        painter->drawText(rect.x() + 3 * rect.width() / 4, rect.y() + 8, 50, 10, Qt::AlignCenter, " - text");
        painter->fillRect(rect.x() + 3 * rect.width() / 4, rect.y() + 30, 10, 10, Qt::green);
        painter->drawText(rect.x() + 3 * rect.width() / 4, rect.y() + 28, 50, 10, Qt::AlignCenter, " - text");

    }

    //painter->restore();
}

} // namespace StyledDelegates
