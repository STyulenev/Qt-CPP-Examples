#pragma once

 // https://qtcentre.org/threads/18633-Images-QTableview-Delegates
//#include <QAbstractItemDelegate>
#include <QSize>
#include <QPixmap>
#include <QPainter>

#include <QItemDelegate>

#include <QDebug>
 
namespace StyledDelegates {

class ImageDelegate : public QItemDelegate//QAbstractItemDelegate
{
public:
	ImageDelegate(QObject * parent = 0);
 
    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const -> void override;
    auto sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const -> QSize override;
};

} // namespace StyledDelegates
