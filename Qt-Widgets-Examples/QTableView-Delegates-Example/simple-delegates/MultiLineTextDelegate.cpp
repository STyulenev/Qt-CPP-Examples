#include "MultiLineTextDelegate.h"

#include <QPlainTextEdit>

namespace SimpleDelegates {

MultiLineTextDelegate::MultiLineTextDelegate(QWidget* parent) :
    QItemDelegate(parent)
{

}

auto MultiLineTextDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QPlainTextEdit* editor = new QPlainTextEdit(parent);
    return editor;
}

auto MultiLineTextDelegate::setEditorData(QWidget* editor,const QModelIndex& index) const -> void
{
    QPlainTextEdit* plainText = qobject_cast<QPlainTextEdit*>(editor);
    QString text = index.data().toString();
    plainText->setPlainText(text);
}

auto MultiLineTextDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QPlainTextEdit* plainText = qobject_cast<QPlainTextEdit*>(editor);
    model->setData(index, plainText->toPlainText(), Qt::EditRole);
}

auto MultiLineTextDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
