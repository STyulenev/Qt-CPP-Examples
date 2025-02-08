import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: customWindow

    visible: true

    width: 920
    height: 500
    minimumHeight: 400
    minimumWidth: 400

    color: "transparent"

    flags: Qt.FramelessWindowHint

    QtObject {
        id: internal

        readonly property int resizeRectangleSize: 5
    }

    Rectangle {
        anchors.fill: parent
        anchors.margins: internal.resizeRectangleSize
        color: "transparent"

        Rectangle {
            id: appBar

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }

            color: "lightblue"
            radius: 10
            height: 50

            MouseArea {
                id: dragMouseArea

                z: 1

                property point clickPos
                property bool isPressed: false

                anchors {
                    fill: parent
                }

                Connections {
                    target: dragMouseArea

                    function onPressed(mouse) {
                        dragMouseArea.isPressed = true;
                        dragMouseArea.clickPos = Qt.point(mouse.x, mouse.y);
                    }

                    function onReleased() {
                        dragMouseArea.isPressed = false;
                    }

                    function onPositionChanged(mouse) {
                        const delta = Qt.point(mouse.x - dragMouseArea.clickPos.x, mouse.y - dragMouseArea.clickPos.y);
                        const tmpX = customWindow.x + delta.x;
                        const tmpY = customWindow.y + delta.y;

                        if (tmpX + customWindow.width > 25 && Screen.desktopAvailableWidth - tmpX > 25)
                            customWindow.x = tmpX;

                        if (tmpY + customWindow.height > 25 && Screen.desktopAvailableHeight - tmpY > 25)
                            customWindow.y = tmpY;
                    }
                }
            }

            RowLayout {
                id: buttons

                z: 2

                anchors {
                    top: parent.top
                    right: parent.right
                    bottom: parent.bottom
                    margins: 5
                }

                Button {
                    id: hideButton

                    Layout.preferredWidth: closeButton.height
                    Layout.fillHeight: true
                    text: "_"

                    onClicked: {
                        customWindow.showMinimized();
                    }
                }

                Button {
                    id: maxButton

                    property bool isMax: false

                    Layout.preferredWidth: closeButton.height
                    Layout.fillHeight: true
                    text: isMax ? "[]" : "[ ]"

                    onClicked: {
                        if (isMax) {
                            customWindow.showNormal();
                            isMax = false;
                        } else {
                            customWindow.showMaximized();
                            isMax = true;
                        }
                    }
                }

                Button {
                    id: closeButton

                    Layout.preferredWidth: closeButton.height
                    Layout.fillHeight: true
                    text: "X"

                    onClicked: {
                        Qt.quit()
                    }
                }
            }
        }

        Rectangle {
            id: body

            anchors {
                top: appBar.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom

                topMargin: 10
            }

            radius: 10
            color: "lightgrey"
        }

        Rectangle {
            id: resizeRectangleRight

            color: "transparent"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            width: internal.resizeRectangleSize

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true
                cursorShape: containsMouse ? Qt.SizeHorCursor : Qt.ArrowCursor

                onPressed: {
                    customWindow.startSystemResize(Qt.RightEdge);
                }
            }
        }

        Rectangle {
            id: resizeRectangleLeft

            color: "transparent"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            width: internal.resizeRectangleSize

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true
                cursorShape: containsMouse ? Qt.SizeHorCursor : Qt.ArrowCursor

                onPressed: {
                    customWindow.startSystemResize(Qt.LeftEdge);
                }
            }
        }

        Rectangle {
            id: resizeRectangleTop

            color: "transparent"

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top

            height: internal.resizeRectangleSize

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true
                cursorShape: containsMouse ? Qt.SizeVerCursor : Qt.ArrowCursor

                onPressed: {
                    customWindow.startSystemResize(Qt.TopEdge);
                }
            }
        }

        Rectangle {
            id: resizeRectangleBottom

            color: "transparent"

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            height: internal.resizeRectangleSize

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true
                cursorShape: containsMouse ? Qt.SizeVerCursor : Qt.ArrowCursor

                onPressed: {
                    customWindow.startSystemResize(Qt.BottomEdge);
                }
            }
        }
    }
}
