#include "ImageDelegate.h"

#include <QPainter>

namespace StyledDelegates {

ImageDelegate::ImageDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{

}

auto ImageDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget*
{
    return nullptr;
}

auto ImageDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize
{
    return QSize(32, 32);
}

void ImageDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QIcon icon(index.data(Qt::DisplayRole).toString());
    QPixmap outPixmap = icon.pixmap(icon.actualSize(this->sizeHint(option, index)));

    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;
    painter->drawPixmap(myOption.rect.x() + option.rect.width() / 2 - this->sizeHint(option, index).width() / 2,
                        myOption.rect.y()+ option.rect.height() / 2 - this->sizeHint(option, index).height() / 2,
                        this->sizeHint(option, index).width(),
                        this->sizeHint(option, index).height(),
                        outPixmap);
}

} // namespace StyledDelegates
