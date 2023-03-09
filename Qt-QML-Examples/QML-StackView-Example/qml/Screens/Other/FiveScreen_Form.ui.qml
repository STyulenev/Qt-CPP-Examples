import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formFiveScreen

    signal clickedBackToThreeScreen
    signal clickedBack

    Row {
        id: buttonRow

        anchors {
            top: parent.top
            left: parent.left
            leftMargin: 10
            topMargin: 10
        }

        spacing: 50

        Button {
            id: buttonBack
            width: 200
            height: 50
            text: "Back"

            Connections {
                target: buttonBack

                function onClicked() {
                    formFiveScreen.clickedBack()
                }
            }
        }

        Button {
            id: buttonBackToThreeScreen
            width: 200
            height: 50
            text: "Back to ThreeScreen"

            Connections {
                target: buttonBackToThreeScreen

                function onClicked() {
                    formFiveScreen.clickedBackToThreeScreen()
                }
            }
        }
    }
}
