#include "LinearGraphicsView.h"

#include "LinearGraphicViewModel.h"

namespace Views {

LinearGraphicsView::LinearGraphicsView(QObject* parent) :
    QObject(parent)
{
    m_firstGraphicName = QString("Chart 1");
    m_firstGraphic  = new ViewModels::LinearGraphicViewModel({{1, 2}, {2,4}, {3,6}}, this);

    m_secondGraphicName = QString("Chart 2");
    m_secondGraphic = new ViewModels::LinearGraphicViewModel({{1, 1}, {2, 2}, {3,3}}, this);
}

auto LinearGraphicsView::getFirstGraphic() const -> QAbstractTableModel*
{
    return m_firstGraphic;
}

auto LinearGraphicsView::getSecondGraphic() const -> QAbstractTableModel*
{
    return m_secondGraphic;
}

auto LinearGraphicsView::getFirstGraphicName() const -> const QString&
{
    return m_firstGraphicName;
}

auto LinearGraphicsView::getSecondGraphicName() const -> const QString&
{
    return m_secondGraphicName;
}

} // namespace Views
