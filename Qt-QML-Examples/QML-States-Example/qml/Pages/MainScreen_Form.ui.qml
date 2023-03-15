import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

// Import C ++ class
import Models 0.1 as Models

Rectangle {
    id: main

    signal changeViewState
    signal changeThemeState

    property bool sunTheme: true
    property bool viewDescription: false

    color: sunTheme ? "#c2f1eb" : "#6c13d0"

    QtObject {
        id: data

        property QtObject model: Models.ListModel {}
    }

    states: [
        State {
            name: "Grid"
            PropertyChanges {
                target: grid
                cellWidth: grid.width / 2
            }
            PropertyChanges {
                target: iconView
                source: "qrc:/res/icons/list.png"
            }
            PropertyChanges {
                target: main
                viewDescription: false
            }
        },
        State {
            name: "List"
            PropertyChanges {
                target: grid
                cellWidth: grid.width
            }
            PropertyChanges {
                target: iconView
                source: "qrc:/res/icons/grid.png"
            }
            PropertyChanges {
                target: main
                viewDescription: true
            }
        }
    ]

    Rectangle {
        id: header
        color: sunTheme ? "#a4e0fc" : "#4416BB"
        height: 50

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right

        }

        Row {
            anchors {
                fill: parent
                margins: 5
            }
            spacing: 10

            Item {
                id: button
                height: parent.height
                width: 50

                Image {
                    id: iconView
                    anchors.centerIn: parent
                    source: "qrc:/res/icons/list.png"
                }

                MouseArea {
                    anchors.fill: parent
                    Connections {
                        function onClicked() {
                            main.changeViewState()
                        }
                    }
                }
            }

            Item {
                id: theme
                height: parent.height
                width: 50

                Image {
                    id: iconTheme
                    anchors.centerIn: parent
                    source: sunTheme ? "qrc:/res/icons/moon.png" : "qrc:/res/icons/sun.png"
                }

                MouseArea {
                    anchors.fill: parent

                    Connections {
                        function onClicked() {
                            main.changeThemeState()
                        }
                    }
                }
            }
        }
    }

    GridView {
        id: grid
        clip: true
        model: data.model

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            leftMargin: 5
            topMargin: 5
        }

        cellWidth: grid.width / 2
        cellHeight: 200

        delegate: Rectangle {
            id: cell

            width: grid.cellWidth - 5
            height: grid.cellHeight - 5

            color: sunTheme ? "#a4e8ec" :  "#6c07f5"
            border.color: "black"
            border.width: 2
            radius: 10

            Text {
                id: title

                anchors {
                    top: cell.top
                    left: parent.left
                    right: parent.right
                }

                height: 30
                text: main.viewDescription ? model.DisplayRole : model.DisplayRole + " " + model.PriceRole + " $"

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                font {
                    family: "Helvetica"
                    pixelSize: 14
                    bold: true
                }
            }

            RowLayout {
                anchors {
                    top: title.bottom
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                }

                Item {
                    id: imageItem

                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    Image {
                        anchors.centerIn: parent
                        source: model.DecorationRole
                    }
                }

                Item {
                    id: descriptionItem
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    visible: main.viewDescription

                    Text {
                        anchors {
                            top: parent.top
                            left: parent.left
                        }

                        text: "\nWeight: " + model.WeightRole + " g.\n" + "Price: " + model.PriceRole + " $"

                        font {
                            family: "Helvetica"
                            pixelSize: 12
                            bold: true
                        }
                    }
                }
            }
        }
    }
}
