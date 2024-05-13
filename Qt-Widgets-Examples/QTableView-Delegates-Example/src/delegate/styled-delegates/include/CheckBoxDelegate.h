#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit CheckBoxDelegate(QObject* parent = nullptr);
    ~CheckBoxDelegate() = default;

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace StyledDelegates

