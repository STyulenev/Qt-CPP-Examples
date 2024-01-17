import QtQuick
import QtQuick.Window

import Components 1.0 as Components

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Test-Example")

    Components.SomeComponent {
        id: root

        anchors.centerIn: parent
    }
}
