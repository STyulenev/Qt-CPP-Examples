import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import Pages 1.0 as Pages

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Loader-Example")

    TabBar {
        id: tabBar

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        TabButton {
            text: qsTr("Example 1")
        }

        TabButton {
            text: qsTr("Example 2")
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

        Pages.Page1 {
            id: page1
        }

        Pages.Page2 {
            id: page2

        }
    }
}
