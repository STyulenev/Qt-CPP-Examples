import QtQuick
import QtQuick.Controls

import uilib as UILib

ApplicationWindow {
    id: app

    visible: true

    width: 600
    height: 600
    title: qsTr("QML-QQmlEngineExtensionPlugin-Example")

    Row {
        anchors.centerIn: parent
        spacing: 10

        UILib.MyTest {
            width: 100
            height: 100
        }

        UILib.MyRectangle {
            width: 100
            height: 100
        }
    }
}
