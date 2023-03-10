import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: formOneScreen

    signal clickedTwoScreen

    Rectangle {
        anchors.fill: parent
        //color: "white"

        ColumnLayout {
            id: column
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right

                leftMargin: 20
                rightMargin: 20
                topMargin: 20
            }

            Label {
                id: name
                Layout.fillWidth: true
                //Layout.minimumHeight: 30
                text: qsTr("Input your name:")

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }

            TextField {
                id: inputName
                Layout.fillWidth: true
                color: Qt.rgba(0.2,0.2,0.2,1);
                placeholderText: qsTr("name")

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }
        }
    }
}
