import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

ApplicationWindow {
    id: mainWindow

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-Animation-Example")

    Row {
        id: layout

        anchors.centerIn: parent

        spacing: 20

        Components.SwitchButton {
            id: switchButton

            width: 200
            height: 50
        }

        Components.SquareSwitchButton {
            id: squareSwitchButton

            width: 100
            height: 100
        }
    }
}
