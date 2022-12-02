#include "DateBoxDelegate.h"

#include <QDateEdit>

namespace SimpleDelegates {

DateBoxDelegate::DateBoxDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto DateBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QDateEdit *editor = new QDateEdit(parent);
    editor->setDisplayFormat("yyyy-MM-dd");
    editor->setCalendarPopup(true);
    return editor;
}

auto DateBoxDelegate::setEditorData(QWidget* editor, const QModelIndex &index) const -> void
{
    QString str = index.model()->data(index).toString();

    QDateEdit* pDate = static_cast<QDateEdit*>(editor);
    pDate->setDate(QDate::fromString(str,"yyyy-MM-dd"));
}

auto DateBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QDateEdit* pDate = static_cast<QDateEdit*>(editor);
    QString str = pDate->date().toString("yyyy-MM-dd");
    model->setData(index,str);
}

auto DateBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
