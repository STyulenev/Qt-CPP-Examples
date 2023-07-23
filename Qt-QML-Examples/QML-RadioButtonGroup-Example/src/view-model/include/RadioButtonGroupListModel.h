#pragma once

#include <QAbstractListModel>
#include <QList>

class RadioButtonGroupListModel final : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(Role)

private:
    struct RadioButtonGroupData {
        QString text;
        bool enabled;
        bool checked;
    };

    QVector<RadioButtonGroupData> listData;
    int currentItem;

public:
    enum Role {
        TextRole = Qt::UserRole + 1,
        EnabledRole,
        CheckedRole
    };

    RadioButtonGroupListModel(const QStringList& options, const int currentItem, QObject* parent);
    virtual ~RadioButtonGroupListModel() = default;

    auto getCurrentItem() const -> int;
    auto setCurrentItem(int newCurrentItem) -> void;

protected:
    virtual auto roleNames() const -> QHash<int, QByteArray> override;
    virtual auto rowCount(const QModelIndex& = QModelIndex()) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;

};

