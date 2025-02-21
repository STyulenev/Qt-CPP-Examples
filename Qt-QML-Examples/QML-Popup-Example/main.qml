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
            text: qsTr("Custom PopupMenu")
        }

        TabButton {
            text: qsTr("Simple Popup")
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

        Rectangle {
            id: page2

            color: "lightblue"

            Text {
                anchors.centerIn: parent
                text: qsTr("Click for creating simple Popup")
            }

            MouseArea {
                anchors.fill: parent

                onClicked: (mouse) => {
                               var c = simplePopupComponent.createObject(page2,
                                                                         {
                                                                             "x": mouse.x,
                                                                             "y": mouse.y
                                                                         });
                               c.open();
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

    Component {
        id: simplePopupComponent

        Popup {
            id: popup

            width: 200
            height: 200

            modal: true
            focus: true
            //closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

            background: Rectangle {
                color: "lightpink"
            }

            Text {
                anchors.centerIn: parent
                text: qsTr("Simple Popup")
            }

            MouseArea {
                anchors.fill: parent

                onClicked: (mouse) => {
                               popup.close();
                               popup.destroy();
                           }
            }
        }
    }
}
