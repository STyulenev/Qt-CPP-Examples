#pragma once

#include <QObject>
#include "LinearGraphicViewModel.h"

namespace Views {

class LinearGraphicsView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractTableModel* firstGraphic READ getFirstGraphic CONSTANT)
    Q_PROPERTY(QAbstractTableModel* secondGraphic READ getSecondGraphic CONSTANT)
    Q_PROPERTY(QString firstGraphicName READ getFirstGraphicName CONSTANT)
    Q_PROPERTY(QString secondGraphicName READ getSecondGraphicName CONSTANT)

private:
    QAbstractTableModel* m_firstGraphic;
    QAbstractTableModel* m_secondGraphic;
    // other ViewModels

    QString m_firstGraphicName;
    QString m_secondGraphicName;

public:
    explicit LinearGraphicsView(QObject* parent = nullptr);
    virtual ~LinearGraphicsView() = default;

    auto getFirstGraphic() const -> QAbstractTableModel*;
    auto getSecondGraphic() const -> QAbstractTableModel*;

    auto getFirstGraphicName() const -> const QString&;
    auto getSecondGraphicName() const -> const QString&;

};

} // namespace Views
