#include "RadioButtonGroupsViewModel.h"

#include "RadioButtonGroupListModel.h"

namespace ViewModels {

RadioButtonGroupsViewModel::RadioButtonGroupsViewModel(QObject* parent) :
    QObject(parent)
{
    QStringList radioButtonList = {
        "Enabled",
        "Disabled",
        "No data"
    };

    m_radioButtonGroupModel = new ViewModels::RadioButtonGroupListModel(radioButtonList, 1, this);
}

auto RadioButtonGroupsViewModel::getRadioButtonGroupModel() const -> QAbstractListModel*
{
    return m_radioButtonGroupModel;
}

} // namespace ViewModels
