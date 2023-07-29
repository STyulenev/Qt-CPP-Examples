#pragma once

#include <QObject>
#include "RadioButtonGroupListModel.h"

namespace Views {

class RadioButtonGroupsView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* radioButtonGroupModel READ getRadioButtonGroupModel NOTIFY radioButtonGroupChanged)

private:
    QAbstractListModel* m_radioButtonGroupModel;
    // other models

public:
    explicit RadioButtonGroupsView(QObject* parent = nullptr);
    virtual ~RadioButtonGroupsView() = default;

    auto getRadioButtonGroupModel() const -> QAbstractListModel*;

signals:
    auto radioButtonGroupChanged() -> void;

};

} // namespace Views
