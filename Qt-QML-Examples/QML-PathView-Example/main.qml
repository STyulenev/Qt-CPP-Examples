import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Models 0.1 as Models

Window {
    id: app

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-PathView-Example")

    property QtObject model: Models.SomeModel {}

    property int itemSize: 80

    PathView {
        id: view

        anchors.centerIn: parent

        width: 500
        height: 500

        model: app.model

        delegate: Item {
            width: PathView.size
            height: PathView.size
            opacity: PathView.opacity

            Column {
                anchors.fill: parent

                Image {
                    id: icon

                    anchors.horizontalCenter: nameText.horizontalCenter
                    width: 64
                    height: 64
                    source: model.display.icon
                }

                Text {
                    id: nameText

                    text: model.display.name
                    font.pointSize: 16
                }
            }
        }

        path: Path {
            startX: 0
            startY: height

            PathAttribute {
                name: "size"
                value: itemSize
            }

            PathAttribute {
                name: "opacity"
                value: 0.5
            }

            PathCurve {
                x: view.width / 5
                y: view.height / 2
            }

            PathCurve {
                x: view.width / 5 * 2
                y: view.height / 4
            }

            PathAttribute {
                name: "size"
                value: itemSize
            }

            PathAttribute {
                name: "opacity"
                value: 0.5
            }
            PathPercent {
                value: 0.49
            }

            PathLine {
                relativeX: 0
                relativeY: 0
            } // разделитель

            PathAttribute {
                name: "size"
                value: itemSize * 2
            }

            PathAttribute {
                name: "opacity"
                value: 1
            }

            PathLine {
                x: view.width / 5 * 3
                y: view.height / 4
            }

            PathAttribute {
                name: "size"
                value: itemSize * 2
            }

            PathAttribute {
                name: "opacity"
                value: 1
            }

            PathPercent {
                value: 0.51
            }

            PathLine {
                relativeX: 0
                relativeY: 0
            }

            PathAttribute {
                name: "size"
                value: itemSize
            }

            PathAttribute {
                name: "opacity"
                value: 0.5
            }

            PathCurve {
                x: view.width / 5 * 4
                y: view.height / 2
            }

            PathCurve {
                x: view.width
                y: view.height
            }

            PathPercent {
                value: 1
            }

            PathAttribute {
                name: "size"
                value: itemSize
            }

            PathAttribute {
                name: "opacity"
                value: 0.5
            }
        }
    }
}
