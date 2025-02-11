#include "SomeModel1.h"

#include <QDebug>

namespace Models {

SomeModel1::SomeModel1() :
    firstField(10),
    secondField("text data")
{

}

SomeModel1::~SomeModel1()
{

}

auto SomeModel1::getFirstField() const -> int
{
    return firstField;
}

auto SomeModel1::getSecondField() const -> const QString&
{
    return secondField;
}

auto SomeModel1::setFirstField(int firstField) -> void
{
    this->firstField = firstField;
}

auto SomeModel1::setSecondField(const QString& secondField) -> void
{
    this->secondField = secondField;
}

QDebug operator<<(QDebug debug, const SomeModel1& someModel)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "SomeModel1 [firstField = "
                    << someModel.getFirstField()
                    << ", setFirstField = "
                    << someModel.getSecondField()
                    << "]";

    return debug;
}

} // namespace Models
