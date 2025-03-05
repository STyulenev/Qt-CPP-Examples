import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: application

    width: Screen.width
    height: Screen.height

    visible: true
    title: qsTr("QML-Android-Example")

    Rectangle {
        id: background

        anchors.fill: parent

        color: "lightblue"

        Label {
            id: title

            anchors.centerIn: parent

            text: qsTr("Hello Android")
            color: "black"
        }
    }
}
