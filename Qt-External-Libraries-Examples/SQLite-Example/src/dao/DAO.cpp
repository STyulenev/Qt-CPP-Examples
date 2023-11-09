#include "DAO.h"

#include <string>
#include <QDebug>

namespace DAO {

PersonDAO::PersonDAO()
{

}

PersonDAO::~PersonDAO()
{
    closeDatabase();
}

bool PersonDAO::openDatabase()
{
    isOpen = (sqlite3_open("/path-to-database/example.db", &db) == SQLITE_OK);
    return isOpen;
}

void PersonDAO::closeDatabase()
{
    if (isOpen)
        sqlite3_close(db);
}

void PersonDAO::selectPeople(QList<Entities::Person>& people)
{
    sqlite3_stmt* stmt = nullptr;

    if (isOpen) {
        sqlite3_prepare(db, "SELECT * FROM \"test.people\";", -1, &stmt, nullptr);
        sqlite3_step(stmt);

        while (sqlite3_column_text(stmt, 0)) {
            Entities::Person person;
            person.setId(std::stoi((char *)sqlite3_column_text(stmt, 0)));
            person.setFirstName(QString((char *)sqlite3_column_text(stmt, 1)));
            person.setLastName(QString((char *)sqlite3_column_text(stmt, 2)));
            person.setAge(std::stoi((char *)sqlite3_column_text(stmt, 3)));

            people << std::move(person);

            sqlite3_step( stmt );
        }
    } else {
        qDebug() << "Failed to open db:" << QString(sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

bool PersonDAO::insertNewPerson(const QString& firstName, const QString& lastName, const int age)
{
    if (isOpen) {
        char* messaggeError;

        const QString query = QString("INSERT INTO \"test.people\" (first_name, last_name, age) VALUES ('%1', '%2', %3);")
                .arg(firstName)
                .arg(lastName)
                .arg(age);

        const int status = sqlite3_exec(db, query.toStdString().c_str(), nullptr, 0, &messaggeError);

        if (status != SQLITE_OK) {
            qDebug() << "Error:" << QString(messaggeError);
            sqlite3_free(messaggeError);

            return false;
        } else
            return true;
    } else {
        return false;
    }
}

bool PersonDAO::insertNewPerson(const Entities::Person& person)
{
    return insertNewPerson(person.getFirstName(), person.getLastName(), person.getAge());
}

bool PersonDAO::deleteById(const int id)
{
    if (isOpen) {
        char* messaggeError;

        const QString query = QString("DELETE FROM \"test.people\" WHERE id = '%1';")
                .arg(id);

        const int status = sqlite3_exec(db, query.toStdString().c_str(), nullptr, 0, &messaggeError);

        if (status != SQLITE_OK) {
            qDebug() << "Error:" << QString(messaggeError);
            sqlite3_free(messaggeError);

            return false;
        } else
            return true;
    } else {
        return false;
    }
}

bool PersonDAO::updatePerson(const int id, const QString& firstName, const QString& lastName, const int age)
{
    if (isOpen) {
        char* messaggeError;

        const QString query = QString("UPDATE \"test.people\" SET first_name = '%1', last_name = '%2', age = %3 WHERE id = %4;")
                .arg(firstName)
                .arg(lastName)
                .arg(age)
                .arg(id);

        const int status = sqlite3_exec(db, query.toStdString().c_str(), nullptr, 0, &messaggeError);

        if (status != SQLITE_OK) {
            qDebug() << "Error:" << QString(messaggeError);
            sqlite3_free(messaggeError);

            return false;
        } else
            return true;
    } else {
        return false;
    }
}

} //namespace DAO
