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

    /*!
     * \brief getXmlAsString
     * \details
     * <!DOCTYPE peoplelist>
     * <data>
     * <description text="This is an example of a list of people in an XML file"/>
     * <people>
     *     <person age="18" email="david.marston@google.com" name="David"/>
     *     // ...
     * </people>
     * </data>
     * \return
     */
    auto createXml() -> QString;

private:
    QString m_description;
    QVector<Person> people;

};
