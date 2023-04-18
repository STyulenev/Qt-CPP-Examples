#include "ListDelegate.h"

#include <QPainter>

namespace Delegates {

ListDelegate::ListDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{

}

auto ListDelegate::createEditor([[maybe_unused]] QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    return nullptr;
}

auto ListDelegate::sizeHint([[maybe_unused]] const QStyleOptionViewItem& option,[[maybe_unused]] const QModelIndex& index) const -> QSize
{
    return QSize(32, 100);
}

auto ListDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    QPixmap outPixmap = index.data(Qt::DecorationRole).value<QPixmap>();

    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;
    painter->drawPixmap(myOption.rect.x() + 5,
                        myOption.rect.y() + 5,
                        32,
                        32,
                        outPixmap);


    QString title = index.data(Qt::DisplayRole).toString();

    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 12)); // font.setBold

    QRect rect(option.rect.x() + 37, myOption.rect.y() + 5, option.rect.width() - 32, 32);
    int flags = Qt::TextWordWrap | Qt::AlignCenter;

    //painter->drawRect(rect);
    painter->drawText(rect, flags, QString("%1").arg(title));

    QString description = index.data(Qt::ToolTipRole).toString();
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 10));
    QRect rectD(option.rect.x(), myOption.rect.y() + 37, option.rect.width(), option.rect.height() - 37);
    int flags2 = Qt::TextWordWrap | Qt::AlignLeft;

    //painter->drawRect(rectD);
    painter->drawText(rectD, flags2, QString("    %1").arg(description));
}

} // namespace Delegates
