import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

import Components 1.0 as Components

ApplicationWindow {
    id: applicationWindow

    width: 840
    height: 480

    minimumHeight: 600
    minimumWidth: 440

    visible: true
    title: qsTr("QML-SplitView-Example")

    /*SplitView {
        id: splitView

        anchors.fill: parent
        orientation: Qt.Horizontal

        Rectangle {
            implicitWidth: 200
            SplitView.maximumWidth: 400
            color: "lightblue"
            Label {
                text: "View 1"
                anchors.centerIn: parent
            }
        }
        Rectangle {
            id: centerItem
            SplitView.minimumWidth: 50
            SplitView.fillWidth: true
            color: "lightgray"
            Label {
                text: "View 2"
                anchors.centerIn: parent
            }
        }
        Rectangle {
            implicitWidth: 200
            color: "lightgreen"
            Label {
                text: "View 3"
                anchors.centerIn: parent
            }
        }
    }*/

    Components.CustomSplitView {
        id: customSplitView

        anchors.fill: parent

        singleComponentBreakPoint: 360 * 2 + 5
        threeComponentBreakPoint: 360 * 3 + 5 + 5

        firstContent: [
            RowLayout {
                id: topPanel1

                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }

                height: 60

                Button {
                    id: prev1

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    text: "to view 2"

                    onClicked: {
                        customSplitView.openSecondPanel();
                    }
                }

                Button {
                    id: next1

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    text: "to view 3"

                    onClicked: {
                        customSplitView.openThirdPanelFromFirstPanel();
                    }
                }
            },

            Text {
                text: "View 1"
                z: 1
                anchors.centerIn: parent
            }
        ]

        secondContent: [
            RowLayout {
                id: topPanel

                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }

                height: 60

                Button {
                    id: prev2

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    visible: !customSplitView.firstContentVisible

                    text: "to view 1"

                    onClicked: {
                        customSplitView.openFirstPanel();
                    }
                }

                Button {
                    id: next2

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    text: "to view 3"

                    onClicked: {
                        customSplitView.openThirdPanel();
                    }
                }
            },

            Text {
                anchors {
                    top: topPanel.bottom
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                }

                text: "View 2"

                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        ]

        thirdContent: [
            Text {
                text: "View 3"
                anchors.centerIn: parent
            },

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    customSplitView.closeThirdPanel();
                }
            }
        ]
    }
}
