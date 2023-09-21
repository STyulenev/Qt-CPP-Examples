#include "SpinBoxDelegate.h"

#include <QSpinBox>

namespace SimpleDelegates {

SpinBoxDelegate::SpinBoxDelegate(int min, int max, int step, QObject* parent) :
    QItemDelegate(parent),
    minValue(min),
    maxValue(max),
    stepValue(step)
{

}

auto SpinBoxDelegate::setRange(const int min, const int max) -> void
{
    minValue = min;
    maxValue = max;
}

auto SpinBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QSpinBox* editor = new QSpinBox(parent);

    editor->setMinimum(minValue);
    editor->setMaximum(maxValue);
    editor->setSingleStep(stepValue);

    return editor;
}

auto SpinBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    int value = index.model()->data(index, Qt::DisplayRole).toDouble();
    QSpinBox* spinBox = qobject_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

auto SpinBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QSpinBox* spinBox = qobject_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

auto SpinBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
