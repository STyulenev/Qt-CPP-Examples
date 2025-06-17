#pragma once

#include <QString>

#include "Person.h"

struct sqlite3;

namespace DAO {

class PersonDAO
{
private:
    sqlite3* db;

    bool isOpen = false;

public:
    PersonDAO();
    ~PersonDAO();

    void selectPeople(QList<Entities::Person>& people);

    bool insertNewPerson(const QString& firstName, const QString& lastName, const int age);
    bool insertNewPerson(const Entities::Person& person);

    bool deleteById(const int id);

    bool updatePerson(const int id, const QString& firstName, const QString& lastName, const int age);

private:
    void init();
    bool openDatabase();
    void closeDatabase();

};

} //namespace DAO
