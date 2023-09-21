#include "ComboBoxDelegate.h"

#include <QComboBox>

namespace SimpleDelegates {

ComboBoxDelegate::ComboBoxDelegate(const QStringList& items, QObject* parent) :
    QItemDelegate(parent),
    m_items(items)
{

}

auto ComboBoxDelegate::setItems(const QStringList& items) -> void
{
    m_items = items;
}

auto ComboBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QComboBox* editor = new QComboBox(parent);
    editor->addItems(m_items);
    editor->installEventFilter(const_cast<ComboBoxDelegate*>(this));
    return editor;
}

auto ComboBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    const QString item = index.model()->data(index).toString();
    QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
    int id = comboBox->findText(item);
    comboBox->setCurrentIndex(id);
}

auto ComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QComboBox* box = qobject_cast<QComboBox*>(editor);
    const  QString item = box->currentText();
    model->setData(index, item);
}

auto ComboBoxDelegate::updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace SimpleDelegates
