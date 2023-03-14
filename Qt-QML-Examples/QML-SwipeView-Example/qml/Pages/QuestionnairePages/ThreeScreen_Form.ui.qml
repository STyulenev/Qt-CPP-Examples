import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formThreeScreen

    property alias inputSex: inputSex

    rightButtonText: qsTr("Next")
    leftButtonText: qsTr("Back")

    content: Rectangle {
        anchors.fill: parent

        ColumnLayout {
            id: column
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: 20
                leftMargin: 20
                rightMargin: 20
            }

            Label {
                id: title
                Layout.fillWidth: true
                text: qsTr("Input your sex:")

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }

            ComboBox {
                id: inputSex
                Layout.fillWidth: true
                Layout.minimumHeight: 40
            }
        }
    }
}
