import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formOneScreen

    signal clickedTwoScreen

    backButtonText: qsTr("Back")

    content: Button {
        id: button
        anchors.centerIn: parent
        width: 100
        height: 50
        text: qsTr("TwoScreen")

        Connections {
            target: button

            function onClicked() {
                formOneScreen.clickedTwoScreen()
            }
        }
    }
}
