#pragma once

#include <QAbstractListModel>

namespace ViewModels {

class ComboBoxViewModel : public QAbstractListModel
{

private:
    struct TestModel {
        QString name;
        QString iconUrl;
    };

    QList<TestModel> model;

public:
    explicit ComboBoxViewModel(QObject* parent = 0);
    virtual ~ComboBoxViewModel() = default;

    virtual auto rowCount(const QModelIndex& parent) const -> int override;
    virtual auto data(const QModelIndex& index, int role) const -> QVariant override;
    virtual auto flags(const QModelIndex& index) const -> Qt::ItemFlags override;
    virtual auto roleNames() const -> QHash<int, QByteArray> override;

};

} // namespace ViewModels
