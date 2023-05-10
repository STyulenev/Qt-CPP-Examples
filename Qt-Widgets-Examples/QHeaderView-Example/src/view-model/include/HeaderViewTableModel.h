#pragma once

#include <QDebug>

#include <QHeaderView>
#include <QPainter>
#include <QMouseEvent>

namespace ViewModels {

class HeaderViewTableModel : public QHeaderView
{
private:
    bool allStatus = false;

public:
    HeaderViewTableModel(Qt::Orientation orientation, QWidget* parent = 0);

protected:
    virtual auto paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const -> void override;

    virtual auto mousePressEvent(QMouseEvent* event) -> void override;
};

} // namespace ViewModels
