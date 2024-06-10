#pragma once

#include <QObject>

namespace Models {

class SomeModel : public QObject
{
    Q_OBJECT

public:
    explicit SomeModel(QObject* parent = nullptr);
    ~SomeModel();

    auto getFirstField() const -> int;
    auto getSecondField() const -> const QString&;

    auto setFirstField(int firstField) -> void;
    auto setSecondField(const QString& secondField) -> void;

private:
    int firstField;
    QString secondField;

};

QDebug operator<<(QDebug debug, const SomeModel& someModel);

} // namespace Models
