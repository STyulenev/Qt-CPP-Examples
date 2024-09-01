import QtQuick 2.15
import QtQuick.Controls 2.15

AbstractWindow {
    id: root

    title: qsTr("Some window")

    signal backData(string data)

    content: Rectangle {
        id: body

        anchors.fill: parent

        color: "lightblue"

        Row {
            anchors.centerIn: parent

            spacing: 20

            Button {
                id: closeButton

                width: 100
                height: 50
                text: qsTr("Close")

                onClicked: {
                    root.closeWindow()
                }
            }

            Button {
                id: backData

                width: 100
                height: 50
                text: qsTr("Back data")

                onClicked: {
                    root.backData("data");
                }
            }
        }
    }
}
