import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import QtCore as Core
import QtQuick.LocalStorage 2.0 as Sql // for DataBase.js
import Logics 1.0 as Logics

Window {
    id: window

    width: 900
    height: 600
    visible: true

    title: qsTr("QML-LocaleStorage-Example")

    Core.Settings {
        category: "General"

        property alias x: window.x
        property alias y: window.y
        property alias width: window.width
        property alias height: window.height
    }

    Text {
        id: text
        anchors.centerIn: parent

        Component.onCompleted: {
            Logics.DataBase.createTablePerson();

            Logics.DataBase.insert("Ben", "Tomson", 66);
            Logics.DataBase.insert('Tom', 'Smith', 37);
            Logics.DataBase.insert('Ken', 'Dyrun', 23);

            text.text = Logics.DataBase.selectAll();
        }
    }
}
