import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.ScrollBar {
    id: scrollBar

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding)

    interactive: true
    padding: 2
    visible: scrollBar.size < 1.0

    Button {
        id: btnDecrease
        anchors.left: parent.left

        Image {
            id: imgDecrease
            anchors.fill: parent
            anchors.margins: parent.width * 0.3
            source: "qrc:/res/white_arrow.svg"
        }

        background: Rectangle {
            anchors.fill: parent
            color: parent.pressed ? Common.Colors.inactiveControlColor : Common.Colors.inactivePressedControlColor
        }

        onClicked: scrollBar.decrease()

        states: [
            State {
                name: "vertical"
                when: scrollBar.orientation === Qt.Vertical
                PropertyChanges {
                    target: btnDecrease
                    height: width
                    anchors.top: parent.top
                    anchors.right: parent.right

                }
                PropertyChanges {
                    target: imgDecrease
                    rotation: 90
                }
            },
            State {
                name: "horizontal"
                when: scrollBar.orientation === Qt.Horizontal
                PropertyChanges {
                    target: btnDecrease
                    width: height
                    anchors.bottom: parent.bottom
                    anchors.top: parent.top
                }
                PropertyChanges {
                    target: imgDecrease
                    rotation: 180
                }
            }
        ]
    }

    contentItem: Rectangle {
        id: slider
        radius: 4 * Common.Consts.radialSize
        color: Common.Colors.currentTheme.mainThemeColor

        states: [
            State {
                name: "vertical"
                when: scrollBar.orientation === Qt.Vertical
                PropertyChanges {
                    target: slider
                    implicitWidth: 10 * Common.Consts.xCoord
                    implicitHeight: 4 * Common.Consts.yCoord
                }
            },
            State {
                name: "horizontal"
                when: scrollBar.orientation === Qt.Horizontal
                PropertyChanges {
                    target: slider
                    implicitWidth: 4 * Common.Consts.xCoord
                    implicitHeight: 10 * Common.Consts.xCoord
                }
            }

        ]
    }

    Button {
        id: btnIncrease
        anchors.right: parent.right

        Image {
            id: imgIncrease
            anchors.fill: parent
            anchors.margins: parent.width * 0.3
            source: "qrc:/res/white_arrow.svg"
        }

        background: Rectangle {
            anchors.fill: parent
            color: parent.pressed ? Common.Colors.inactiveControlColor : Common.Colors.inactivePressedControlColor
        }

        onClicked: scrollBar.increase()

        states: [
            State {
                name: "vertical"
                when: scrollBar.orientation === Qt.Vertical
                PropertyChanges {
                    target: btnIncrease
                    height: width
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left

                }
                PropertyChanges {
                    target: imgIncrease
                    rotation: -90
                }
            },
            State {
                name: "horizontal"
                when: scrollBar.orientation === Qt.Horizontal
                PropertyChanges {
                    target: btnIncrease
                    width: height
                    anchors.bottom: parent.bottom
                    anchors.top: parent.top
                }
            }
        ]
    }

    background: Rectangle {
        color:  Common.Colors.inactiveControlColor
        visible: scrollBar.visible
    }

    states: [
        State {
            name: "vertical"
            when: scrollBar.orientation === Qt.Vertical
            PropertyChanges {
                target: scrollBar
                topPadding: btnDecrease.height
                bottomPadding: btnIncrease.height

            }
        },
        State {
            name: "horizontal"
            when: scrollBar.orientation === Qt.Horizontal
            PropertyChanges {
                target: btnIncrease
                leftPadding: btnDecrease.width
                rightPadding: btnIncrease.width
            }
        }
    ]
}
