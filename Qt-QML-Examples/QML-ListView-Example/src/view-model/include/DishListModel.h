#pragma once

#include <QObject>
#include <QQmlListProperty>

#include <DishModel.h>

namespace ViewModels {

class DishListModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Models::DishModel> data READ data NOTIFY dataChanged)
    QML_LIST_PROPERTY_ASSIGN_BEHAVIOR_REPLACE_IF_NOT_DEFAULT
    Q_CLASSINFO("DefaultProperty", "data")

public:
    explicit DishListModel(QObject* parent = nullptr);
    ~DishListModel();

    QQmlListProperty<Models::DishModel> data();

    Q_INVOKABLE void add();

signals:
    void dataChanged();

private:
    static void appendData(QQmlListProperty<Models::DishModel>* list, Models::DishModel* value);
    static qsizetype countData(QQmlListProperty<Models::DishModel>* list);
    static Models::DishModel* atData(QQmlListProperty<Models::DishModel>* list, qsizetype index);
    static void clearData(QQmlListProperty<Models::DishModel>* list);

    QList<Models::DishModel*> m_data;

};

} // namespace ViewModels
