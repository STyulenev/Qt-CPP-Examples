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

            height: 200
            width: 200

            count: 5
            currentValue: 2
        }

        Components.Battery {
            id: battery

            orientation: Qt.Vertical // Qt.Horizontal

            height: battery.orientation === Qt.Vertical ? 200 : 120
            width: battery.orientation === Qt.Vertical ? 120 : 200

            count: 4
            charge: 50 // %
        }

        Components.SoundLevel {
            id: sound

            size: 200

            count: 5
            value: 2
        }
    }*/

    /*Components.SimpleTable {
        id: simpleTable

        anchors.centerIn: parent

        model: Models.SimpleTableModel {
            column: 3
            myArray: [0, 1, 2, 7, 8, 9]
        }

        height: 200
        width: 300
    }*/

    Components.Carousel {
        id: carousel

        anchors.centerIn: parent

        height: 300
        width: 300

        model: [
            {
                "color": "lightgreen",
                "text": "first"
            },
            {
                "color": "lightblue",
                "text": "second"
            },
            {
                "color": "lightgrey",
                "text": "third"
            }
        ]
    }
}
