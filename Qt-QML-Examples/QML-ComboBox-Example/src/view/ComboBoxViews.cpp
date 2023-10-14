#include "ComboBoxViews.h"

namespace Views {

ComboBoxViews::ComboBoxViews(QObject* parent) :
    QObject(parent)
{
    m_comboBoxViewModel = new ViewModels::ComboBoxViewModel(this);
}

auto ComboBoxViews::getComboBoxViewModel() const -> QAbstractListModel*
{
    return m_comboBoxViewModel;
}

} // namespace Views
