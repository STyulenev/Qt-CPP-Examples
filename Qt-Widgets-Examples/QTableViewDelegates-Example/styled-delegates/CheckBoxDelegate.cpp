#include "CheckBoxDelegate.h"

#include <QApplication>
#include <QCheckBox>

namespace StyledDelegates {

CheckBoxDelegate::CheckBoxDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{

}

auto CheckBoxDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    QCheckBox* editor = new QCheckBox(parent);
    editor->installEventFilter(const_cast<CheckBoxDelegate*>(this));
    return editor;
}

auto CheckBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(editor);
    checkBox->setChecked(index.data().toBool());
}

auto CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(editor);
    model->setData(index, (checkBox->checkState() == Qt::Checked), Qt::EditRole);
}

auto CheckBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex &index) const -> void
{
    QStyleOptionButton checkboxstyle;
    QRect checkbox_rect = QApplication::style()->subElementRect(QStyle::SE_CheckBoxIndicator, &checkboxstyle);

    checkboxstyle.rect = option.rect;
    checkboxstyle.rect.setLeft(option.rect.x() + option.rect.width() / 2 - checkbox_rect.width() / 2);

    editor->setGeometry(checkboxstyle.rect);
}

auto CheckBoxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    bool data = index.model()->data(index, Qt::DisplayRole).toBool();

    QStyleOptionButton checkboxstyle;
    QRect checkbox_rect = QApplication::style()->subElementRect(QStyle::SE_CheckBoxIndicator, &checkboxstyle);

    checkboxstyle.rect = option.rect;
    checkboxstyle.rect.setLeft(option.rect.x() + option.rect.width() / 2 - checkbox_rect.width() / 2);

    checkboxstyle.state = (data) ? QStyle::State_On | QStyle::State_Enabled : QStyle::State_Off | QStyle::State_Enabled;

    QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkboxstyle, painter);
}

} // namespace StyledDelegates
