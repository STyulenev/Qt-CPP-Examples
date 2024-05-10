#pragma once

#include <QStyledItemDelegate>

#include <TestModel.h>

namespace Delegates {

class QComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    QComboBoxDelegate(QObject* parent = nullptr);
    ~QComboBoxDelegate();

    auto sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const -> QSize override;
    auto paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const -> void override;

};

} // namespace Delegates
