#pragma once

#include <QItemDelegate>

namespace CustomDelegates {

class CustomRadioButtonDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CustomRadioButtonDelegate(QObject* parent = nullptr);
    virtual ~CustomRadioButtonDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace CustomDelegates
