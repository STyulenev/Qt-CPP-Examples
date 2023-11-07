#pragma once

#include <sqlite3.h>
#include <QString>

#include "Person.h"

class DAO
{
public:
    DAO();
    ~DAO();

    bool openDatabase();
    void closeDatabase();

    void/*QList<Person>*/ selectPeople();

    void insertNewPerson(/*const QString& firstName, const QString& lastName, const int age*/);

private:
    sqlite3* db;

    bool isOpen = false;

};
