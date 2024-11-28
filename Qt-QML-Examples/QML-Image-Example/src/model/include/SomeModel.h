#pragma once

#include <QObject>

class SomeModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString image READ getImage CONSTANT)

public:
    explicit SomeModel(QObject *parent = nullptr);
    ~SomeModel();

    const QString& getImage() const;

private:
    QString m_image;

};
