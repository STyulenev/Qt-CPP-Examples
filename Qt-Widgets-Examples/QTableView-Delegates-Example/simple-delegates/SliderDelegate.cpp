#include "SliderDelegate.h"

#include <QPainter>

namespace SimpleDelegates {

SliderDelegate::SliderDelegate(int min, int max, int step, QObject *parent)
    : QItemDelegate(parent),
      min(min),
      max(max),
      step(step)
{

}

auto SliderDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget*
{
    QSlider* editor = new QSlider(Qt::Horizontal, parent);
    editor->setRange(min, max);
    editor->setSingleStep(step);
    editor->setTickPosition(QSlider::TickPosition::TicksBelow);
    editor->setAutoFillBackground(true);
    return editor;
}

auto SliderDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    QSlider* slider = qobject_cast<QSlider*>(editor);
    const int value = index.model()->data(index).toInt();
    slider->setValue(value);
}

auto SliderDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QSlider* slider = qobject_cast<QSlider*>(editor);
    model->setData(index, slider->value(), Qt::EditRole);
}

auto SliderDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
