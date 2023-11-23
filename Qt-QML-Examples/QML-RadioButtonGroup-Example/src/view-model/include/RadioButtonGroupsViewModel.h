#pragma once

#include <QObject>
#include <QAbstractListModel> //or class QAbstractListModel;

namespace ViewModels {

class RadioButtonGroupsViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* radioButtonGroupModel READ getRadioButtonGroupModel NOTIFY radioButtonGroupChanged)

private:
    QAbstractListModel* m_radioButtonGroupModel;
    // other models

public:
    explicit RadioButtonGroupsViewModel(QObject* parent = nullptr);
    virtual ~RadioButtonGroupsViewModel() = default;

    auto getRadioButtonGroupModel() const -> QAbstractListModel*;

signals:
    auto radioButtonGroupChanged() -> void;

};

} // namespace ViewModels
