#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class ImageDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ImageDelegate(QObject* parent = nullptr);
    ~ImageDelegate() = default;

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;

};

} // namespace StyledDelegates
