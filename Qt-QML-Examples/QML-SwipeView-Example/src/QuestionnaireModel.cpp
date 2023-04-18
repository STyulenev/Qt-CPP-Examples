#include "QuestionnaireModel.h"

namespace ViewModels {

QuestionnaireModel::QuestionnaireModel(QObject* parent) :
    QObject(parent)
{
    this->_name = "noname";
    this->_age = 18;
    this->_sex = Sex::Unknown;
}

QuestionnaireModel::~QuestionnaireModel()
{

}

auto QuestionnaireModel::getName() const -> QString
{
    return this->_name;
}

auto QuestionnaireModel::getAge() const -> int
{
    return this->_age;
}

auto QuestionnaireModel::getSex() const -> Sex
{
    return this->_sex;
}

auto QuestionnaireModel::setName(const QString& newName) -> void
{
    if (!newName.isEmpty() && newName != this->_name) {
        this->_name = newName;

        emit nameChanged();
    }
}

auto QuestionnaireModel::setAge(const int& newAge) -> void
{
    this->_age = newAge;

    emit ageChanged();
}

auto QuestionnaireModel::setSex(const Sex& newSex) -> void
{
    this->_sex = newSex;

    emit sexChanged();
}

} // namespace ViewModels
