#pragma once

#include <QString>
#include <QDebug>

struct Person {
public:
    int id;
    QString firstName;
    QString lastName;
    int age;

    void print() const {
        qDebug() << id << firstName << lastName << age;
    }
};
