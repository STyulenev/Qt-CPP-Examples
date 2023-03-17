#include "QComboBoxDelegate.h"

#include <QApplication>
#include <QPainter>
#include <QDebug>

namespace Delegates {

QComboBoxDelegate::QComboBoxDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{

}

QComboBoxDelegate::~QComboBoxDelegate()
{

}

auto QComboBoxDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    size.setHeight(40);
    return size;
}

auto QComboBoxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    QString data  = index.model()->data(index, Qt::DisplayRole).toString();
    QPixmap image = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();

    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;
    painter->drawPixmap(myOption.rect.x() + 5, myOption.rect.y() + 4, 32, 32, image);

    QTextOption testOption;
    testOption.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    QRect rectText(option.rect);
    rectText.setX(rectText.x() + 40);

    painter->setFont(QFont("Times", 12, QFont::Bold));
    painter->drawText(rectText, QString("%1").arg(data), testOption);
}

} // namespace Delegates
