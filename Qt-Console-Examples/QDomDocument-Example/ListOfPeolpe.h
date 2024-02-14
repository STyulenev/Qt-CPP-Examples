#pragma once

#include <QObject>
#include <QDomDocument>

struct Person {
    QString name;
    QString email;
    int age;
};

class ListOfPeolpe : public QObject
{
    Q_OBJECT
public:
    explicit ListOfPeolpe(QObject* parent = nullptr);
    ~ListOfPeolpe() = default;

    auto setDescription(const QString& description) -> void;
    auto getDescription() const -> const QString&;

    auto addPerson(const QString& name, const QString& email, const int age) -> void;

    auto getXmlAsString() -> QString;

private:
    QString m_description;
    QVector<Person> people;

};
