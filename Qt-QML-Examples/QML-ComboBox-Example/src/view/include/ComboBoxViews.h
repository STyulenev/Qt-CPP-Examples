#pragma once

#include <QObject>
#include "ComboBoxViewModel.h"

namespace Views {

class ComboBoxViews : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* comboBoxViewModel READ getComboBoxViewModel NOTIFY comboBoxViewModelChanged)

private:
    QAbstractListModel* m_comboBoxViewModel;
    // other ViewModels

public:
    explicit ComboBoxViews(QObject* parent = nullptr);
    virtual ~ComboBoxViews() = default;

    auto getComboBoxViewModel() const -> QAbstractListModel*;

signals:
    auto comboBoxViewModelChanged() -> void;

};

} // namespace Views
