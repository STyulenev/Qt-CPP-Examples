#include "DAO.h"

#include <string>
#include <QDebug>

#ifdef SQLITE_WITH_ENCRIPTION
#include <sqlite3mc/sqlite3.h>
#include <sqlite3mc/sqlite3mc.h>
#else
#include <sqlite3.h>
#endif

namespace {
    const char* createDBQuery =
        "CREATE TABLE IF NOT EXISTS \"test.people\" ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "first_name TEXT,"
        "last_name TEXT,"
        "age INTEGER"
        ");";

    const char* insertQuery =
    "INSERT INTO \"test.people\" (first_name, last_name, age) VALUES ('Tom', 'Smith', 37);"
    "INSERT INTO \"test.people\" (first_name, last_name, age) VALUES ('Ken', 'Dyrun', 23);"
                              "INSERT INTO \"test.people\" (first_name, last_name, age) VALUES ('Ken12', 'Dyrun12', 23);";

    std::string password = "password"; // "PRAGMA key = 'my_secret_key';";

    int callback(void* data, int argc, char** argv, char** azColName) {
        qDebug() << "Query results:\n";
        for(int i = 0; i<argc; i++) {
            qDebug() << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL");
        }
        return 0;
    }
}

namespace DAO {

PersonDAO::PersonDAO()
{
    init();
}

PersonDAO::~PersonDAO()
{
    closeDatabase();
}

void PersonDAO::init()
{
    int errorCode;
    char* errorMessage = 0;

    // Инициализация SQLCipher
    errorCode = sqlite3_initialize();
    if (errorCode) {
        qDebug() << "Can't initialize SQLCipher: " << sqlite3_errmsg(0);
        return;
    }

    // Создание и открытие базы данных
    errorCode = sqlite3_open("encrypted.db", &db);

    if (errorCode == SQLITE_OK) {
        qDebug() << "The database exists";


#ifdef SQLITE_WITH_ENCRIPTION
        errorCode = sqlite3_key(db, password.c_str(), password.size());
        if (errorCode) {
            qDebug() << "Can't open database: " << sqlite3_errmsg(db);
            sqlite3_close(db);
            return;
        }
#endif

        errorCode = sqlite3_exec(db, ::createDBQuery, ::callback, 0, &errorMessage);
        if(errorCode != SQLITE_OK) {
            qDebug() << "Failed to create table: " << errorMessage;
            sqlite3_free(errorMessage);
            sqlite3_close(db);
            return;
        }

        errorCode = sqlite3_exec(db, ::insertQuery, ::callback, 0, &errorMessage);
        if(errorCode != SQLITE_OK) {
            qDebug() << "Failed to create table: " << errorMessage;
            sqlite3_free(errorMessage);
            sqlite3_close(db);
            return;
        }
    } else {
        qDebug() << "The database does not exist: " << sqlite3_errmsg(db);
    }

    isOpen = true;
}

bool PersonDAO::openDatabase()
{
    return isOpen;
}

void PersonDAO::closeDatabase()
{
    if (isOpen) {
        sqlite3_close(db);
        sqlite3_shutdown();
    }
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

} // namespace DAO
