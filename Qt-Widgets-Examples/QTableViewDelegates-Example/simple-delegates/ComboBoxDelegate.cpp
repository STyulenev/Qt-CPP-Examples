#include "ComboBoxDelegate.h"

#include <QComboBox>

namespace SimpleDelegates {

ComboBoxDelegate::ComboBoxDelegate(QStringList items, QObject* parent)
    : QItemDelegate(parent),
      m_sItemList(items)
{

}

auto ComboBoxDelegate::setItems(QStringList items) -> void
{
    m_sItemList = items;
}

auto ComboBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QComboBox* editor = new QComboBox(parent);
    editor->addItems(m_sItemList);
    editor->installEventFilter(const_cast<ComboBoxDelegate*>(this));
    return editor;
}

auto ComboBoxDelegate::setEditorData(QWidget* editor,const QModelIndex& index) const -> void
{
    QString str = index.model()->data(index).toString();
    QComboBox* box = static_cast<QComboBox*>(editor);
    int i = box->findText(str);
    box->setCurrentIndex(i);
}

auto ComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QComboBox* box = static_cast<QComboBox*>(editor);
    QString str = box->currentText();
    model->setData(index,str);
}

auto ComboBoxDelegate::updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
