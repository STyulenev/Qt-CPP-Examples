import QtQuick
import Felgo

AppPage {

    title: "Second Page"

    AppButton {
        text: "Back"
        anchors.centerIn: parent

        onClicked: {
            navigationStack.pop()
        }
    }

}
