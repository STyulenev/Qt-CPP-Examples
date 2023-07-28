#pragma once

#include <QObject>
#include "LinearGraphicViewModel.h"

namespace Views {

class LinearGraphicsView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractTableModel* firstGraphic READ getFirstGraphic CONSTANT)
    Q_PROPERTY(QAbstractTableModel* secondGraphic READ getSecondGraphic CONSTANT)

private:
    QAbstractTableModel* m_firstGraphic;
    QAbstractTableModel* m_secondGraphic;
    // other ViewModels

public:
    explicit LinearGraphicsView(QObject* parent = nullptr);
    virtual ~LinearGraphicsView() = default;

    auto getFirstGraphic() const -> QAbstractTableModel*;
    auto getSecondGraphic() const -> QAbstractTableModel*;

};

} // namespace Views
