#include "StyledSliderDelegate.h"

#include <QPainter>

namespace StyledDelegates {

StyledSliderDelegate::StyledSliderDelegate(int min, int max, int step, QObject* parent) :
    QStyledItemDelegate(parent),
    step(step),
    max(max),
    min(min)
{

}

auto StyledSliderDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QSlider* editor = new QSlider(Qt::Horizontal, parent);

    editor->setRange(min, max);
    editor->setSingleStep(step);
    editor->setTickPosition(QSlider::TickPosition::TicksBelow);
    editor->setAutoFillBackground(true);

    return editor;
}

auto StyledSliderDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    QSlider* slider = qobject_cast<QSlider*>(editor);
    const int value = index.model()->data(index).toInt();
    slider->setValue(value);
}

auto StyledSliderDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QSlider* slider = qobject_cast<QSlider*>(editor);
    model->setData(index, slider->value());
}

auto StyledSliderDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    painter->save();
    QRect rect(option.rect);
    const int value = index.model()->data(index).toInt();
    const int width = (value * rect.width()) / 100;
    rect.setWidth(width);
    QColor color;

    switch (value) {
    case 0 ... 19:
        color = Qt::red;
        break;
    case 20 ... 49:
        color = QColor(255, 153, 51);
        break;
    case 50 ... 69:
        color = Qt::yellow;
        break;
    case 70 ... 100:
        color = Qt::green;
        break;
    default:
        assert(!"bad value");
    }

    painter->fillRect(rect, color);
    QTextOption testOption;
    testOption.setAlignment(Qt::AlignCenter);
    painter->drawText(option.rect, QString("%1 %").arg(value), testOption);

    painter->restore();
}

auto StyledSliderDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace StyledDelegates
