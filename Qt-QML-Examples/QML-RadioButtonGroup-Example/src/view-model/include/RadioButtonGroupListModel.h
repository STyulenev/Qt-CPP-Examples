#pragma once

#include <QAbstractListModel>

namespace ViewModels {

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
        EnabledRole = Qt::UserRole + 1,
        CheckedRole
    };

    RadioButtonGroupListModel(QObject* parent) = delete;
    explicit RadioButtonGroupListModel(const QStringList& options, const int currentItem, QObject* parent);
    virtual ~RadioButtonGroupListModel() = default;

    auto getCurrentItem() const -> int;
    auto setCurrentItem(int newCurrentItem) -> void;

protected:
    virtual auto rowCount(const QModelIndex& = QModelIndex()) const -> int override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto setData(const QModelIndex& index, const QVariant& value, int role) -> bool override;
    virtual auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
