import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components
import Models 1.0 as Models

Window {
    id: app

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-Repeater-Example")

    /*Row {
        anchors.centerIn: parent
        spacing: 20

        Components.SignalLevel {
            id: signalLevel

            height: 100
            width: 100

            count: 5
            currentValue: 2
        }

        Components.Battery {
            id: battery

            height: 100
            width: 60

            count: 4
            charge: 50 // %
        }
    }*/

    Components.SimpleTable {
        id: simpleTable

        anchors.centerIn: parent

        model: Models.SimpleTableModel {
            column: 3
            myArray: [0, 1, 2, 7, 8, 9]
        }

        height: 200
        width: 300
    }
}
