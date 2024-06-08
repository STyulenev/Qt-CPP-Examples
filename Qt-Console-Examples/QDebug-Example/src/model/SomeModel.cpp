#include "SomeModel.h"

#include <QDebug>

namespace Models {

SomeModel::SomeModel(QObject* parent) :
    QObject(parent)
{

}

SomeModel::~SomeModel()
{

}

QDebug operator<<(QDebug debug, const SomeModel& someModel)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "SomeModel";

    return debug;
}

} // namespace Models
