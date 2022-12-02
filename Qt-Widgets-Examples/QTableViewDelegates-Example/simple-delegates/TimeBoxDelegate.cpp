#include "TimeBoxDelegate.h"

#include <QTimeEdit>

namespace SimpleDelegates {

TimeBoxDelegate::TimeBoxDelegate(QObject* parent) :
    QItemDelegate(parent)
{

}

auto TimeBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QTimeEdit *editor = new QTimeEdit(parent);
    editor->setDisplayFormat("hh:mm:ss");
    editor->setCalendarPopup(true);
    return editor;
}

auto TimeBoxDelegate::setEditorData(QWidget* editor,const QModelIndex &index) const -> void
{
    QTimeEdit* pTime = static_cast<QTimeEdit*>(editor);
    pTime->setTime(index.model()->data(index).toTime());
}

auto TimeBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex &index) const -> void
{
    QTimeEdit* pTime = static_cast<QTimeEdit*>(editor);
    QString str = pTime->time().toString("hh:mm:ss");
    model->setData(index,str);
}

auto TimeBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
