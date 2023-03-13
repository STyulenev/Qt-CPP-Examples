import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: base
    //property string screenName: "Screen"
    //property alias buttonBackEnabled: btnBack.visible

    property alias content: itmArea.children

    signal leftButtonClicked
    signal rightButtonClicked

    property alias rightButtonText: rightButton.text
    property alias leftButtonText: leftButton.text
    property alias rightButtonVisible: rightButton.visible
    property alias leftButtonVisible: leftButton.visible

    Item {
        id: itmArea

        anchors {
            top: parent.top
            bottom: footerArea.top
            left: parent.left
            right: parent.right
        }
    }

    Item {
        id: footerArea
        height: 50

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        RowLayout {
            anchors.fill: parent
            spacing: 10

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: 5
                Layout.topMargin: 5
                Layout.bottomMargin: 10

                Button {
                    id: leftButton
                    text: "Left Button"
                    anchors.fill: parent

                    onClicked: base.leftButtonClicked()
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: 5
                Layout.topMargin: 5
                Layout.bottomMargin: 10

                Button {
                    id: rightButton
                    text: "Right Button"
                    anchors.fill: parent

                    onClicked: base.rightButtonClicked()
                }
            }
        }
    }
}
