#pragma once

#include <QStyledItemDelegate>

namespace StyledDelegates {

class StyledPieChartDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit StyledPieChartDelegate(QObject* parent = nullptr);
    virtual ~StyledPieChartDelegate() = default;

protected:
    virtual auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const -> QSize override;
    virtual auto createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const -> QWidget* override;
    virtual auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace StyledDelegates
