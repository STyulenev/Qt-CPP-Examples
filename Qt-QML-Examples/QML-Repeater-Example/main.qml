import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

Window {
    id: app

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-Repeater-Example")

    Row {
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
    }
}
