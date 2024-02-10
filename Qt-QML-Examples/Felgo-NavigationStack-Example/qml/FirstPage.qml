import QtQuick
import Felgo

AppPage {
    id: firstPage
    title: "FirstPage"

    Component {
        id: secondPage

        SecondPage {

        }
    }

    AppButton {
        text: "to the second page"
        anchors.centerIn: parent

        onClicked: {
            navigationStack.push(secondPage)
        }
    }
}
