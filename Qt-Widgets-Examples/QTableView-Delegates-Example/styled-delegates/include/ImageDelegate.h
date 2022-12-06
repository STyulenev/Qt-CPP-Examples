#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class ImageDelegate : public QStyledItemDelegate
{
public:
    ImageDelegate(QObject * parent = nullptr);
 
    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const -> void override;
    auto sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const -> QSize override;
};

} // namespace StyledDelegates
