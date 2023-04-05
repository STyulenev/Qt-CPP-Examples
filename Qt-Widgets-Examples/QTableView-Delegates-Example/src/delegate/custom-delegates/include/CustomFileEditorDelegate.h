#pragma once

#include <QItemDelegate>

namespace CustomDelegates {

class CustomFileEditorDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    CustomFileEditorDelegate(QObject* parent = nullptr);

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
};

} // namespace CustomDelegates
