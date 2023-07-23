#include "RadioButtonGroupsView.h"

RadioButtonGroupsView::RadioButtonGroupsView(QObject* parent) :
    QObject(parent)
{
    QStringList radioButtonList = {
        "Enabled",
        "Disabled",
        "No data"
    };

    m_radioButtonGroupModel = new RadioButtonGroupListModel(radioButtonList, 1, this);
}

auto RadioButtonGroupsView::getRadioButtonGroupModel() const -> QAbstractListModel*
{
    return m_radioButtonGroupModel;
}
