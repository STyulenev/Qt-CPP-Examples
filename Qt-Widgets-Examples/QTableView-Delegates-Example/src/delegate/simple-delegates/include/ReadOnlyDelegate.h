#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class ReadOnlyDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit ReadOnlyDelegate(QObject* parent = nullptr);
    virtual ~ReadOnlyDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget*;

};

} // namespace SimpleDelegates
