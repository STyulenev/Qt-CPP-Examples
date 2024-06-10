#include "SomeModel.h"

#include <QDebug>

namespace Models {

SomeModel::SomeModel(QObject* parent) :
    QObject(parent),
    firstField(10),
    secondField("text data")
{

}

SomeModel::~SomeModel()
{

}

auto SomeModel::getFirstField() const -> int
{
    return firstField;
}

auto SomeModel::getSecondField() const -> const QString&
{
    return secondField;
}

auto SomeModel::setFirstField(int firstField) -> void
{
    this->firstField = firstField;
}

auto SomeModel::setSecondField(const QString& secondField) -> void
{
    this->secondField = secondField;
}

QDebug operator<<(QDebug debug, const SomeModel& someModel)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "SomeModel [firstField = "
                    << someModel.getFirstField()
                    << ", setFirstField = "
                    << someModel.getSecondField()
                    << "]";

    return debug;
}

} // namespace Models
