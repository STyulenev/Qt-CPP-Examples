#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class LineEditDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    LineEditDelegate(QObject* parent = nullptr);

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
};

} // namespace SimpleDelegates
