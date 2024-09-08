import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

import Screens 1.0 as Screens

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Dialog-Example")

    Screens.SomeScreen {
        anchors.fill: parent
    }
}
