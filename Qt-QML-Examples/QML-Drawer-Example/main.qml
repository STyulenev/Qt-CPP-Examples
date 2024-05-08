import QtQuick 2.15
import QtQuick.Window 2.15

import Screens 1.0 as Screens

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Drawer-Example")

    Screens.SomeScreen {
        anchors.fill: parent
    }
}
