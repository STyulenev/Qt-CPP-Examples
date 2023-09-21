#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class StyledSliderDelegate : public QStyledItemDelegate
{
    Q_OBJECT

private:
    int min;
    int max;
    int step;

public:
    explicit StyledSliderDelegate(int min = 0, int max = 100, int step = 1, QObject* parent = nullptr);
    virtual ~StyledSliderDelegate() = default;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace StyledDelegates
