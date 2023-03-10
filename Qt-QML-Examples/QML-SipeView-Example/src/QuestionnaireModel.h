#pragma once

#include <QObject>

namespace ViewModels {

class QuestionnaireModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(Sex sex READ getSex WRITE setSex NOTIFY sexChanged)

public:
    explicit QuestionnaireModel(QObject* parent = 0);
    virtual ~QuestionnaireModel();

    enum Sex {
        Male,
        Female,
        Unknown
        // ...
    };
    Q_ENUM(Sex)

    auto getName() const -> QString;
    auto getAge() const -> int;
    auto getSex() const -> Sex;

    auto setName(const QString& newName) -> void;
    auto setAge(const int& newAge) -> void;
    auto setSex(const Sex& newSex) -> void;

signals:
    void nameChanged();
    void ageChanged();
    void sexChanged();

private:
    QString _name;
    int     _age;
    Sex     _sex;

};

} // namespace ViewModels
