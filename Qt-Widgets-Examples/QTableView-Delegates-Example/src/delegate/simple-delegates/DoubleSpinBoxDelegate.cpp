#include "DoubleSpinBoxDelegate.h"

#include <QDoubleSpinBox>

namespace SimpleDelegates {

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(double min, double max, double step, QObject* parent)
    : QItemDelegate(parent),
      minValue(min),
      maxValue(max),
      stepValue(step)
{

}

auto DoubleSpinBoxDelegate::setRange(double min, double max) -> void
{
    minValue = min;
    maxValue = max;
}

auto DoubleSpinBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QDoubleSpinBox* editor = new QDoubleSpinBox(parent);

    editor->setMinimum(minValue);
    editor->setMaximum(maxValue);
    editor->setSingleStep(stepValue);

    return editor;
}

auto DoubleSpinBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    double value = index.model()->data(index, Qt::DisplayRole).toDouble();
    QDoubleSpinBox* spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

auto DoubleSpinBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QDoubleSpinBox* spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    double value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

auto DoubleSpinBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
