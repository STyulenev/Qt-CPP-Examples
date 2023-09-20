#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class SpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT

private:
    int minValue;
    int maxValue;
    int stepValue;

public:
    explicit SpinBoxDelegate(int min = 0, int max = 100, int step = 1, QObject* parent = nullptr);
    virtual ~SpinBoxDelegate() = default;

    auto setRange(const int min, const int max) -> void;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace SimpleDelegates
