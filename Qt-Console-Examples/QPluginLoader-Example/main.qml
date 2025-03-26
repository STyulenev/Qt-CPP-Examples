import QtQuick
import QtQuick.Controls

import ui.components 1.0 as UILib

ApplicationWindow {
    id: app

    visible: true

    width: 600
    height: 600
    title: qsTr("QPluginLoader-Example")

    UILib.MyTest {
        anchors.centerIn: parent

        width: 100
        height: 100
    }
}
