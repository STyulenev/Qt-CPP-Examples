import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import QtCore as Core
import QtQuick.LocalStorage 2.0 as Sql

// https://doc.qt.io/qt-6/qtquick-localstorage-qmlmodule.html
// https://russianblogs.com/article/80431214069/

Window {
    id: window
    width: 900
    height: 600
    visible: true
    title: qsTr("Hello World")

    Core.Settings {
        property alias x: window.x
        property alias y: window.y
        property alias width: window.width
        property alias height: window.height
    }

    Text {
        text: "?"
        anchors.horizontalCenter: parent.horizontalCenter
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

        function select() {
            var db = Sql.LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers its position", 100000);
            db.transaction( function(tx) {
                print('... select table')

                var result = tx.executeSql('SELECT * FROM data');

                for (var i = 0; i < result.rows.length; i++) {
                    console.log(i + " name = " + result.rows.item(i).name + " value = " + result.rows.item(i).value);
                }
            });
        }

        Component.onCompleted: {
            //findGreetings()
            //insert();
            select();
        }
    }
}
