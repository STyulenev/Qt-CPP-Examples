#include "ListDelegate.h"

#include <QPainter>

namespace Delegates {

ListDelegate::ListDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{
    titleFlags = Qt::TextWordWrap | Qt::AlignCenter;
    descriptionFlags = Qt::TextWordWrap | Qt::AlignLeft;

    titleFont.setFamily("Arial");
    titleFont.setPixelSize(16);
    titleFont.setBold(true);

    descriptionFont.setFamily("Arial");
    descriptionFont.setPixelSize(12);
}

ListDelegate::~ListDelegate()
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
    painter->drawPixmap(myOption.rect.x() + 5, myOption.rect.y() + 5, 32, 32, outPixmap);

    painter->setPen(Qt::black);

    QString title = index.data(Qt::DisplayRole).toString();
    painter->setFont(titleFont);
    QRect rectTitle(option.rect.x() + 42, myOption.rect.y() + 5, option.rect.width() - 47, 32);
    //painter->drawRect(rectTitle);
    painter->drawText(rectTitle, titleFlags, title);

    QString description = index.data(Qt::ToolTipRole).toString();
    painter->setFont(descriptionFont);
    QRect rectDescription(option.rect.x() + 5, myOption.rect.y() + 37, option.rect.width() - 10, option.rect.height() - 37);
    //painter->drawRect(rectDescription);
    painter->drawText(rectDescription, descriptionFlags, QString("    %1").arg(description));
}

} // namespace Delegates
