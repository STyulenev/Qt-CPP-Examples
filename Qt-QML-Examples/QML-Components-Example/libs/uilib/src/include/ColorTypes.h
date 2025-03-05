#pragma once

#include <QObject>

class ColorTypes : public QObject
{
    Q_OBJECT
public:
    enum Color
    {
        Black,
        Grey,
        // ...,
        Yellow,
        Pink
        // ...
    };
    Q_ENUM(Color)

    // ...

};
