#pragma once

#include <QAbstractTableModel>
#include <DAO.h>

namespace ViewModels {

class PersonsViewModel : public QAbstractTableModel
{
public:
    explicit PersonsViewModel(QObject* parent = 0);
    virtual ~PersonsViewModel();

    virtual auto columnCount(const QModelIndex& parent) const -> int override;
    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

private:
    QList<Entities::Person> people;
    DAO::PersonDAO* dao;

};

} // namespace ViewModels
