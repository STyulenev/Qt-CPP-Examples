#include "CustomColorEditorDelegate.h"

#include "ColorEditor.h"

#include <QPainter>

namespace CustomDelegates {

CustomColorEditorDelegate::CustomColorEditorDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto CustomColorEditorDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    ColorEditor* widget = new ColorEditor(parent);
    widget->setGeometry(option.rect);
    return widget;
}

auto CustomColorEditorDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    ColorEditor* widget = qobject_cast<ColorEditor*>(editor);
    auto data = index.data(Qt::DisplayRole).toString();
    widget->setColor(data);
}

auto CustomColorEditorDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    ColorEditor* widget = qobject_cast<ColorEditor*>(editor);
    model->setData(index, widget->getColor(), Qt::EditRole);
}

auto CustomColorEditorDelegate::sizeHint([[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QSize
{
    return QSize(32, 32);
}

auto CustomColorEditorDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    painter->save();
    QRect rect(option.rect);
    rect.setWidth(rect.width() / 2);

    QString colorName = index.data(Qt::DisplayRole).toString();
    QColor color(colorName);

    painter->fillRect(rect, color);
    QTextOption testOption;
    testOption.setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    painter->drawText(option.rect, QString("%1").arg(colorName), testOption);

    painter->restore();
}

auto CustomColorEditorDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace CustomDelegates
