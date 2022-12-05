#include "ReadOnlyDelegate.h"

namespace SimpleDelegates {

ReadOnlyDelegate::ReadOnlyDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

auto ReadOnlyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const -> QWidget*
{
    return NULL;
}

} // namespace SimpleDelegates
