#pragma once

#include <QItemDelegate>

namespace CustomDelegates {

class CustomFileEditorDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CustomFileEditorDelegate(QObject* parent = nullptr);
    virtual ~CustomFileEditorDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace CustomDelegates
