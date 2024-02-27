import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

Window {
    id: app

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Repeater-Example")

    Components.SignalLevel {
        id: signalLevel

        height: 200
        width: 200

        count: 5
        currentValue: 2
    }
}
