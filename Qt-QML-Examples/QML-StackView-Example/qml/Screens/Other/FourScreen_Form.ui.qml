import QtQuick 2.15
import QtQuick.Controls 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formFourScreen

    signal clickedFourScreen

    backButtonText: qsTr("Back")

    content: Button {
        id: printButton
        anchors.centerIn: parent
        width: 100
        height: 50
        text: qsTr("FiveScreen")

        Connections {
            target: printButton

            function onClicked() {
                formFourScreen.clickedFourScreen()
            }
        }
    }
}
