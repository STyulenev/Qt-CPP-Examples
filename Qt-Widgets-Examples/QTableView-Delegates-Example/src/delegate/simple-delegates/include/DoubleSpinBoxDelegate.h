#pragma once

#include <QItemDelegate>

namespace SimpleDelegates {

class DoubleSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT

private:
    double minValue;
    double maxValue;
    double stepValue;

public:
    explicit DoubleSpinBoxDelegate(double min = 0.0, double max = 100.0, double step = 0.01, QObject* parent = nullptr);
    virtual ~DoubleSpinBoxDelegate() = default;

    auto setRange(const double min, const double max) -> void;

protected:
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto setEditorData(QWidget* editor, const QModelIndex& index) const -> void override;
    virtual auto setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const -> void override;
    virtual auto updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace SimpleDelegates
