import QtQuick
import Felgo

AppPage {
    id: firstPage
    title: qsTr("First page")

    signal clicked()

    AppButton {
        id: button

        text: qsTr("To the second page")
        anchors.centerIn: parent

        Connections {
            target: button

            onClicked: {
                firstPage.clicked();
            }
        }
    }
}
