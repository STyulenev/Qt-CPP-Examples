function findGreetings() {
    var db = Sql.LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers its position", 100000);
    db.transaction( function(tx) {
        print('... create table')
        tx.executeSql('CREATE TABLE IF NOT EXISTS data(name TEXT, value TEXT)');
    });
}

function insert() {
    var db = Sql.LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers its position", 100000);
    db.transaction( function(tx) {
        print('... insert table')
        tx.executeSql('INSERT INTO data(name, value) VALUES (\'123\', \'123\')');
    });
}

function selectAll() {
    var db = Sql.LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers its position", 100000);
    db.transaction( function(tx) {
        print('... select table')

        var result = tx.executeSql('SELECT * FROM data');

        for (var i = 0; i < result.rows.length; i++) {
            console.log(i + " name = " + result.rows.item(i).name + " value = " + result.rows.item(i).value);
        }
    });
}
