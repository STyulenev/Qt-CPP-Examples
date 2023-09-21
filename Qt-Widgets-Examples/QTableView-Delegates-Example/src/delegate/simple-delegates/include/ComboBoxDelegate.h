#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT

private:
    QStringList m_items;

public:
    explicit ComboBoxDelegate(const QStringList& items, QObject* parent = nullptr);
    virtual ~ComboBoxDelegate() = default;

    auto setItems(const QStringList& items) -> void;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace SimpleDelegates
