#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class DateBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    DateBoxDelegate(QObject* parent = 0);

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
};

} // namespace SimpleDelegates
