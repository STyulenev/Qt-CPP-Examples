#include "CustomRadioButtonDelegate.h"

#include "WidgetWithTwoRadioButtons.h"

#include <QPainter>

namespace CustomDelegates {

CustomRadioButtonDelegate::CustomRadioButtonDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto CustomRadioButtonDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    WidgetWithTwoRadioButtons* widget = new WidgetWithTwoRadioButtons(parent);
    widget->setGeometry(option.rect);
    return widget;
}

auto CustomRadioButtonDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    WidgetWithTwoRadioButtons* widget = qobject_cast<WidgetWithTwoRadioButtons*>(editor);
    widget->setStatus(index.data(Qt::DisplayRole).toBool());
}

auto CustomRadioButtonDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    WidgetWithTwoRadioButtons* widget = qobject_cast<WidgetWithTwoRadioButtons*>(editor);
    model->setData(index, widget->getStatus(), Qt::EditRole);
}

auto CustomRadioButtonDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    painter->save();
    QRect rect(option.rect);

    const bool value = index.model()->data(index).toBool();

    QColor color = value ? Qt::green : Qt::red;

    painter->fillRect(rect, color);
    QTextOption testOption;
    testOption.setAlignment(Qt::AlignCenter);
    painter->drawText(option.rect, QString("%1").arg(value ? "True" : "False"), testOption);
    painter->restore();
}

auto CustomRadioButtonDelegate::updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace CustomDelegates
