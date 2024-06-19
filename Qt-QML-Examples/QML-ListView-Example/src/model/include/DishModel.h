#pragma once

#include <QObject>

namespace Models {

class DishModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString iconUrl READ iconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool status READ status WRITE setStatus NOTIFY statusChanged)

public:
    explicit DishModel(QObject* parent = nullptr);
    ~DishModel();

    QString name() const;
    QString iconUrl() const;
    QString description() const;
    bool status() const;

    void setName(const QString &newName);
    void setIconUrl(const QString &newIconUrl);
    void setDescription(const QString &newDescription);
    void setStatus(bool newStatus);

signals:
    void nameChanged();
    void iconUrlChanged();
    void descriptionChanged();
    void statusChanged();

private:
    QString m_name;
    QString m_iconUrl;
    QString m_description;
    bool    m_status;

};

} // namespace Models
