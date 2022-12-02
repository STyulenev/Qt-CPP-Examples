#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class DoubleSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    DoubleSpinBoxDelegate(double min = 0.0, double max = 100.0, double step = 0.01, QObject* parent = 0);

    auto setRange(double min, double max) -> void;

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

private:
    double minValue;
    double maxValue;
    double stepValue;
};

} // namespace SimpleDelegates
