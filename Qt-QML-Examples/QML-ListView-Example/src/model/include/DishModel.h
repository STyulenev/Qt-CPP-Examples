#pragma once

#include <QObject>

namespace Models {

class DishModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString iconUrl READ getIconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool status READ getStatus WRITE setStatus NOTIFY statusChanged)

public:
    explicit DishModel(QObject* parent = nullptr);
    ~DishModel();

    auto getName() const -> const QString&;
    auto getIconUrl() const -> const QString&;
    auto getDescription() const -> const QString&;
    auto getStatus() const -> bool;

    auto setName(const QString& name) -> void;
    auto setIconUrl(const QString& iconUrl) -> void;
    auto setDescription(const QString& description) -> void;
    auto setStatus(bool status) -> void;

signals:
    auto nameChanged() -> void;
    auto iconUrlChanged() -> void;
    auto descriptionChanged() -> void;
    auto statusChanged() -> void;

private:
    QString m_name;
    QString m_iconUrl;
    QString m_description;
    bool    m_status;

};

} // namespace Models
