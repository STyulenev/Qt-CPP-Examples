import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Forms 1.0 as Forms

Forms.BaseForm {
    id: formSplashScreen

    signal clickedService
    signal clickedOther

    screenName: "Splash Screen"

    Row {
        id: buttonRow
        anchors.centerIn: parent
        spacing: 50

        Button {
            id: buttonService
            width: 150
            height: 50
            text: "Service"

            Connections {
                target: buttonService

                function onClicked() {
                    formSplashScreen.clickedService()
                }
            }
        }

        Button {
            id: buttonOther
            width: 150
            height: 50
            text: "Other"

            Connections {
                target: buttonOther

                function onClicked() {
                    formSplashScreen.clickedOther()
                }
            }
        }
    }
}
