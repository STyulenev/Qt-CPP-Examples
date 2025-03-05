import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: app

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-ToolTip-Example")

    ColumnLayout {
        id: body

        anchors.centerIn: parent

        spacing: 10

        Button {
            id: button

            text: qsTr("Button with simple ToolTip")

            Layout.preferredWidth: 200
            Layout.preferredHeight: 50

            hoverEnabled: true

            ToolTip.delay: 1000
            ToolTip.timeout: 5000
            ToolTip.visible: hovered
            ToolTip.text: qsTr("This is ToolTip.")
        }

        Button {
            id: button2

            text: qsTr("Button with custom ToolTip")

            Layout.preferredWidth: 200
            Layout.preferredHeight: 50

            hoverEnabled: true

            ToolTip {
                id: customToolTip

                delay: 1000
                timeout: 5000
                visible: button2.hovered
                text: qsTr("This is ToolTip.")

                contentItem: Text {
                    color: "black"
                    text: customToolTip.text
                }

                background: Rectangle {
                    id: bg

                    color: "lightblue"
                    radius: 5

                    border {
                        width: 2
                        color: "black"
                    }
                }
            }
        }
    }
}
