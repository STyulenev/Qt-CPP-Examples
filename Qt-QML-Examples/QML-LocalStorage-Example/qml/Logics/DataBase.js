var db = Sql.LocalStorage.openDatabaseSync("QML-LocaleStorage-Example", "1.0", "A sample of LocaleStorage", 100000);

function createTablePerson() {
    db.transaction( function(tx) {
        console.log('Create table people');
        tx.executeSql(
                    `
                    CREATE TABLE IF NOT EXISTS people
                    (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        first_name TEXT,
                        last_name TEXT,
                        age INTEGER
                    );
                    `
        );
    });
}

function insert(first_name, last_name, age) {
    db.transaction( function(tx) {
        console.log('insert table')
        tx.executeSql(`INSERT INTO people(first_name, last_name, age) VALUES (\'${first_name}\', \'${last_name}\', ${age});`);
    });
}

function selectAll() {
    var list = "";

    db.transaction( function(tx) {
        console.log('select from table')

        var result = tx.executeSql('SELECT * FROM people;');

        for (var i = 0; i < result.rows.length; i++) {
            list += `id = ${result.rows.item(i).id}, first_name = ${result.rows.item(i).first_name}, last_name, = ${result.rows.item(i).last_name}, age = ${result.rows.item(i).age}\n`;
        }
    });

    return list;
}
