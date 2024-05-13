#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class StyledPieChartDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit StyledPieChartDelegate(QObject* parent = nullptr);
    ~StyledPieChartDelegate() = default;

    auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const -> QSize override;
    auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace StyledDelegates
