#pragma once

#include <QObject>
#include <QMetaType>

namespace Models {

class SomeModel1
{
public:
    SomeModel1();
    ~SomeModel1();

    auto getFirstField() const -> int;
    auto getSecondField() const -> const QString&;

    auto setFirstField(int firstField) -> void;
    auto setSecondField(const QString& secondField) -> void;

private:
    int firstField;
    QString secondField;

};

QDebug operator<<(QDebug debug, const SomeModel1& someModel);

} // namespace Models

Q_DECLARE_METATYPE(Models::SomeModel1)
Q_DECLARE_METATYPE(Models::SomeModel1*)
// ...

static const int someClass1TypeId = qMetaTypeId<Models::SomeModel1>();
