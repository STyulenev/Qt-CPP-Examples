#include "LineEditDelegate.h"

#include <QLineEdit>

namespace SimpleDelegates {

LineEditDelegate::LineEditDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto LineEditDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QLineEdit* editor = new QLineEdit(parent);
    //editor->setValidator(...);
    return editor;
}

auto LineEditDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
    lineEdit->setText(index.data().toString());
}

auto LineEditDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
    QString text = lineEdit->text();
    model->setData(index, text, Qt::EditRole);
}

auto LineEditDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
