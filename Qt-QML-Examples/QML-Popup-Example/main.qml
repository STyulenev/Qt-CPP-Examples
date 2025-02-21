import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Components 1.0 as Components

Window {
    id: app

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Popup-Example")

    TabBar {
        id: tabBar

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        TabButton {
            text: qsTr("PopupMenu")
        }
    }

    StackLayout {
        id: stackLayout

        anchors {
            top: tabBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        currentIndex: tabBar.currentIndex

        Rectangle {
            id: page1

            color: "lightgreen"

            Text {
                anchors.centerIn: parent
                text: "Click for creating PopupMenu"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: (mouse) => {
                    var c = popupMenuComponent.createObject(page1, {});
                    c.open(mouse.x, mouse.y);
                }
            }
        }
    }

    Component {
        id: popupMenuComponent

        Components.PopupMenu {
            id: contextMenu

            Components.MenuItem {
                text: qsTr("Item 1")
                onClicked: console.log("onClicked: Item 1")
            }

            Components.MenuItem {
                text: qsTr("Item 2")
                onClicked: console.log("onClicked: Item 2")
            }

            // ...
        }
    }
}
