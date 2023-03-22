#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class StyledSliderDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit StyledSliderDelegate(int min = 0, int max = 100, int step = 1, QObject* parent = nullptr);

    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

private:
    int min;
    int max;
    int step;
};

} // namespace StyledDelegates
