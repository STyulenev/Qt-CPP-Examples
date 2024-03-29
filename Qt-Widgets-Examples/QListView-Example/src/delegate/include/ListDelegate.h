#pragma once

#include <QStyledItemDelegate>

namespace Delegates {

class ListDelegate : public QStyledItemDelegate
{
private:
    int titleFlags;
    int descriptionFlags;
    QFont titleFont;
    QFont descriptionFont;

public:
    ListDelegate(QObject* parent = nullptr);
    virtual ~ListDelegate();
 
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const -> QSize override;
};

} // namespace Delegates
