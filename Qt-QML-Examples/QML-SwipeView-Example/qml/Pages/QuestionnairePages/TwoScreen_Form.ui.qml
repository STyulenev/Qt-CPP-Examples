import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Forms 1.0 as Forms

Forms.BaseForm {
    id: formTwoScreen

    property alias inputAge: inputAge.text

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

                leftMargin: 20
                rightMargin: 20
                topMargin: 20
            }

            Label {
                id: title
                Layout.fillWidth: true
                text: qsTr("Input your age:")

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }

            TextField {
                id: inputAge
                Layout.fillWidth: true
                color: Qt.rgba(0.2, 0.2, 0.2, 1);
                placeholderText: qsTr("age...")
                validator: CommonData.RegExp.ageValidator

                font {
                    family: "Helvetica"
                    pixelSize: 20
                    bold: false
                }
            }
        }
    }
}
