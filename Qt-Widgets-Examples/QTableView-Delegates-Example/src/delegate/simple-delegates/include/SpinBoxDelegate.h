#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class SpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(int min = 0, int max = 100, int step = 1, QObject* parent = nullptr);

    auto setRange(int min, int max) -> void;

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

private:
    int minValue;
    int maxValue;
    int stepValue;
};

} // namespace SimpleDelegates
