#include "CustomFileEditorDelegate.h"

#include "FileEditor.h"

#include <QPainter>

namespace CustomDelegates {

CustomFileEditorDelegate::CustomFileEditorDelegate(QObject* parent)
    : QItemDelegate(parent)
{

}

auto CustomFileEditorDelegate::createEditor(QWidget* parent, [[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QWidget*
{
    FileEditor* widget = new FileEditor(parent);
    widget->setGeometry(option.rect);
    return widget;
}

auto CustomFileEditorDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const -> void
{
    FileEditor* widget = qobject_cast<FileEditor*>(editor);
    auto data = index.data(Qt::DisplayRole).toByteArray();
    if (!data.isEmpty())
        widget->setImage(data);
}

auto CustomFileEditorDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void
{
    FileEditor* widget = qobject_cast<FileEditor*>(editor);
    model->setData(index, widget->getImage(), Qt::EditRole);
}

auto CustomFileEditorDelegate::sizeHint([[maybe_unused]] const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> QSize
{
    return QSize(32, 32);
}

auto CustomFileEditorDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void
{
    QByteArray bytea(index.data(Qt::DisplayRole).toByteArray());
    if (bytea.isEmpty()) {
        return;
    } else {
        QPixmap outPixmap;
        outPixmap.loadFromData(bytea);
        outPixmap.scaled(this->sizeHint(option, index));

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;
        painter->drawPixmap(myOption.rect.x() + option.rect.width() / 2 - this->sizeHint(option, index).width() / 2,
                            myOption.rect.y()+ option.rect.height() / 2 - this->sizeHint(option, index).height() / 2,
                            this->sizeHint(option, index).width(),
                            this->sizeHint(option, index).height(),
                            outPixmap);
    }
}

auto CustomFileEditorDelegate::updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, [[maybe_unused]] const QModelIndex& index) const -> void
{
    editor->setGeometry(option.rect);
}

} // namespace CustomDelegates
