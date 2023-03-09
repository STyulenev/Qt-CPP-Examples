import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formTwoScreen

    signal clickedPrintLog
    signal clickedBack

    Button {
        id: printButton
        anchors.centerIn: parent
        width: 100
        height: 50
        text: "Print Log"

        Connections {
            target: printButton

            function onClicked() {
                formTwoScreen.clickedPrintLog()
            }
        }
    }

    Button {
        id: backButton

        anchors {
            top: parent.top
            left: parent.left
            leftMargin: 10
            topMargin: 10
        }

        width: 100
        height: 50
        text: "Back"

        Connections {
            target: backButton

            function onClicked() {
                formTwoScreen.clickedBack()
            }
        }
    }
}
