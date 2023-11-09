#pragma once

#include <sqlite3.h>
#include <QString>

#include "Person.h"

namespace DAO {

class PersonDAO
{
private:
    sqlite3* db;

    bool isOpen = false;

public:
    PersonDAO();
    ~PersonDAO();

    bool openDatabase();
    void closeDatabase();

    void selectPeople(QList<Entities::Person>& people);

    bool insertNewPerson(const QString& firstName, const QString& lastName, const int age);
    bool insertNewPerson(const Entities::Person& person);

    bool deleteById(const int id);

    bool updatePerson(const int id, const QString& firstName, const QString& lastName, const int age);

};

} //namespace DAO
