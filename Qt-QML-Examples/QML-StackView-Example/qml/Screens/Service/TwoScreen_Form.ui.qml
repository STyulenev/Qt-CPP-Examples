import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formTwoScreen

    signal clickedPrintLog

    backButtonText: qsTr("Back")

    content: Button {
        id: printButton
        anchors.centerIn: parent
        width: 100
        height: 50
        text: qsTr("Print Log")

        Connections {
            target: printButton

            function onClicked() {
                formTwoScreen.clickedPrintLog()
            }
        }
    }
}
