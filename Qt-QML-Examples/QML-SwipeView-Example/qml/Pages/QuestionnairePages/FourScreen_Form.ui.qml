import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Forms 1.0 as Forms

Forms.BaseForm {
    id: formFourScreen

    rightButtonText: qsTr("Exit")
    leftButtonText: qsTr("Start over")

    property alias labelName: labelName.text
    property alias labelAge: labelAge.text
    property alias labelSex: labelSex.text

    content: Rectangle {
        anchors.fill: parent

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
                id: labelName
                Layout.fillWidth: true

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }

            Label {
                id: labelAge
                Layout.fillWidth: true

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }

            Label {
                id: labelSex
                Layout.fillWidth: true

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }
        }
    }
}
