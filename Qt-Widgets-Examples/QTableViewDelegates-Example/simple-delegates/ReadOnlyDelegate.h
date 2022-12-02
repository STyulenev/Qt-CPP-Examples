#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class ReadOnlyDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ReadOnlyDelegate(QObject* parent = nullptr);

    auto createEditor(QWidget *parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget*;
};

} // namespace SimpleDelegates
