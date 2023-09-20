#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class MultiLineTextDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit MultiLineTextDelegate(QWidget* parent = 0);
    virtual ~MultiLineTextDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace SimpleDelegates
