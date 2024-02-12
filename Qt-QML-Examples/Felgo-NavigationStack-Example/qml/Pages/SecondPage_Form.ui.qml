import QtQuick
import Felgo

AppPage {
    id: secondPage
    title: qsTr("Second Page")

    signal clicked()

    AppButton {
        id: button

        text: qsTr("Back")
        anchors.centerIn: parent

        Connections {
            target: button

            onClicked: {
                secondPage.clicked();
            }
        }
    }
}
