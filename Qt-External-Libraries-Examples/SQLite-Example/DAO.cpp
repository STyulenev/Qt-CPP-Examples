#include "DAO.h"

#include <string>
#include <QDebug>

DAO::DAO()
{

}

DAO::~DAO()
{
    closeDatabase();
}

bool DAO::openDatabase()
{
    isOpen = (sqlite3_open("/home/sergey/Examples/SQLite-Example/example.db", &db) == SQLITE_OK);
    return isOpen;
}

void DAO::closeDatabase()
{
    if (isOpen)
        sqlite3_close(db);
}

void/*QList<Person>*/ DAO::selectPeople()
{
    sqlite3_stmt* stmt;
    QVector<Person> persons;

    if (isOpen) {
        sqlite3_prepare(db, "SELECT * FROM \"test.people\";", -1, &stmt, NULL); //preparing the statement
        sqlite3_step(stmt); //executing the statement

        while (sqlite3_column_text(stmt, 0)) {
            Person person;
            person.id = std::stoi((char *)sqlite3_column_text(stmt, 0));
            person.firstName = QString((char *)sqlite3_column_text(stmt, 1));
            person.lastName = QString((char *)sqlite3_column_text(stmt, 2));
            person.age = std::stoi((char *)sqlite3_column_text(stmt, 3));

            persons << std::move(person);

            sqlite3_step( stmt );
        }

        for (int i = 0; i < persons.size(); ++i) {
            persons[i].print();
        }
    } else {
        qDebug() << "Failed to open db\n";
        qDebug() << "Error open DB " << QString(sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);

    //return QList<Person>;
}

void DAO::insertNewPerson(/*const QString &firstName, const QString &lastName, const int age*/)
{
    if (isOpen) {
        char *zErrMsg = 0;

        std::string sql = "INSERT INTO \"test.people\" (first_name, last_name, age) VALUES ('Ken2', 'Dyrun2', 23);";

        // Run the SQL (convert the string to a C-String with c_str() )
        int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    }
}
