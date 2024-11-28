#include "SomeModel.h"

#include <QFile>
#include <QByteArray>

SomeModel::SomeModel(QObject* parent) :
    QObject(parent)
{
    QFile file(":/res/grid.png");
    QByteArray data;

    if (file.open(QIODevice::ReadOnly))
        data = file.readAll();

    m_image = "data:image/png;base64," + QString(data.toBase64());
}

SomeModel::~SomeModel()
{

}

const QString &SomeModel::getImage() const
{
    return m_image;
}
