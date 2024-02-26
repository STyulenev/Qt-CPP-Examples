import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: base

    property string screenName: "Screen"

    signal exit()
    signal next(Component screen)
    signal replace(Component screen)
    signal backTo(string name)

    signal backButtonClicked()

    property alias content: bodyItem.children
    property alias backButtonText: backButton.text
    property alias backButtonVisible: backButton.visible

    Button {
        id: backButton
        text: qsTr("Back Button")
        anchors {
            top: parent.top
            left: parent.left
            leftMargin: 5
            topMargin: 5
        }

        width: 100
        height: 40

        onClicked: base.backButtonClicked()
    }

    Item {
        id: bodyItem

        anchors {
            fill: parent
            topMargin: 50
        }
    }
}
