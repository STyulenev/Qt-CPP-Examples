#include "ListOfPeolpe.h"

ListOfPeolpe::ListOfPeolpe(QObject* parent) :
    QObject(parent)
{
    m_description = "This is an example of a list of people in an XML file";

    people = {
                 {"David", "david.marston@google.com", 18}
             };
}

auto ListOfPeolpe::setDescription(const QString& description) -> void
{
    this->m_description = description;
}

auto ListOfPeolpe::getDescription() const -> const QString&
{
    return this->m_description;
}

auto ListOfPeolpe::addPerson(const QString& name, const QString& email, const int age) -> void
{
    Person person;
    person.name = name;
    person.email = email;
    person.age = age;

    people.append(std::move(person));
}

auto ListOfPeolpe::getXmlAsString() -> QString
{
    QDomDocument doc("peoplelist");
    QDomElement  mainElement = doc.createElement("data");
    doc.appendChild(mainElement);

    {
        QDomElement descriptionElement = doc.createElement("description");
        QDomAttr descriptionAttr = doc.createAttribute("text");
        descriptionAttr.setValue(m_description);
        descriptionElement.setAttributeNode(descriptionAttr);
        doc.appendChild(descriptionElement);
    }

    {
        QDomElement listElement = doc.createElement("people");

        for (const Person& person : people) {
            QDomElement personElement = doc.createElement("person");

            QDomAttr nameAttr = doc.createAttribute("name");
            nameAttr.setValue(person.name);
            personElement.setAttributeNode(nameAttr);
            listElement.appendChild(personElement);

            QDomAttr emailAttr = doc.createAttribute("email");
            emailAttr.setValue(person.email);
            personElement.setAttributeNode(emailAttr);
            listElement.appendChild(personElement);

            QDomAttr ageAttr = doc.createAttribute("age");
            ageAttr.setValue(QString::number(person.age));
            personElement.setAttributeNode(ageAttr);
            listElement.appendChild(personElement);
        }

        doc.appendChild(listElement);
    }

    return doc.toString();
}
