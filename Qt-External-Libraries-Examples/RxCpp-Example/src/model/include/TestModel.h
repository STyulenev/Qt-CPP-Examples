#pragma once

#include <QString>

namespace Models {

class TestModel
{
public:
    enum Sex {
        MALE = 1,
        FEMALE
    };

    TestModel();
    TestModel(const QString& name, const TestModel::Sex sex, const int age);
    ~TestModel();

    auto getName() const -> const QString&;
    auto getSex() const -> Sex;
    auto getAge() const -> int;

    auto setName(const QString& name) -> void;
    auto setSex(Sex newSex) -> void;
    auto setAge(int newAge) -> void;

private:
    QString m_name;
    Sex m_sex;
    int m_age;
};

} // namespace Models
