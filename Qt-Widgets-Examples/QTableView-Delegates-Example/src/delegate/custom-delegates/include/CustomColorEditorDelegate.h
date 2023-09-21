#pragma once

#include <QItemDelegate>

namespace CustomDelegates {

class CustomColorEditorDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CustomColorEditorDelegate(QObject* parent = nullptr);
    virtual ~CustomColorEditorDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace CustomDelegates
