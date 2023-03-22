#include "ReadOnlyDelegate.h"

namespace SimpleDelegates {

ReadOnlyDelegate::ReadOnlyDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto ReadOnlyDelegate::createEditor([[maybe_unused]] QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex &index) const -> QWidget*
{
    return nullptr;
}

} // namespace SimpleDelegates
