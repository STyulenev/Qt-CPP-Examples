#pragma once

#include <QObject>

namespace Models {

class SomeModel : public QObject
{
    Q_OBJECT

public:
    explicit SomeModel(QObject* parent = nullptr);
    ~SomeModel();


};

QDebug operator<<(QDebug debug, const SomeModel& someModel);

} // namespace Models
