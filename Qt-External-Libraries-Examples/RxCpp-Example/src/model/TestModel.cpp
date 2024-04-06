#include "TestModel.h"

namespace Models {

TestModel::TestModel()
{

}

TestModel::TestModel(const QString& name, const Sex sex, const int age) :
    m_name(name),
    m_sex(sex),
    m_age(age)
{

}

TestModel::~TestModel()
{

}

const QString& TestModel::getName() const
{
    return m_name;
}

auto TestModel::setName(const QString& name) -> void
{
    m_name = name;
}

auto TestModel::getSex() const -> TestModel::Sex
{
    return m_sex;
}

auto TestModel::setSex(Sex sex) -> void
{
    m_sex = sex;
}

auto TestModel::getAge() const -> int
{
    return m_age;
}

auto TestModel::setAge(int age) -> void
{
    m_age = age;
}

} // namespace Models
