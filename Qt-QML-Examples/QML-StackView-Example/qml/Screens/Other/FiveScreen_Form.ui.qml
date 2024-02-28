import QtQuick 2.15
import QtQuick.Controls 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formFiveScreen

    signal clickedBackToThreeScreen

    backButtonText: qsTr("Back")

    content: Button {
        id: printButton
        anchors.centerIn: parent
        width: 200
        height: 50
        text: qsTr("Back To Three Screen")

        Connections {
            target: printButton

            function onClicked() {
                formFiveScreen.clickedBackToThreeScreen()
            }
        }
    }
}
