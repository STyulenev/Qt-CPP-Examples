#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class ImageDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ImageDelegate(QObject* parent = nullptr);
    virtual ~ImageDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;

};

} // namespace StyledDelegates
