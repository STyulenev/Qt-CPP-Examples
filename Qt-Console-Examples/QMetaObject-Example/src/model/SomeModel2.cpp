#include "SomeModel2.h"

namespace Models {

SomeModel2::SomeModel2(QObject* parent) :
    QObject(parent)
{

}

SomeModel2::~SomeModel2()
{

}

QString SomeModel2::getData()
{
    return this->data;
}

void SomeModel2::setData(const QString &data)
{
    this->data = data;
}

} // namespace Models
