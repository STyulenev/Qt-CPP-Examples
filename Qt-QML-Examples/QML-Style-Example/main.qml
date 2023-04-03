import QtQml 2.6
import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Layouts 1.6

import Common 1.0 as Common

ApplicationWindow {
    id: appWindow
    visible: true
    width: Common.Consts.screenWidth
    height: Common.Consts.screenHeight
    /*maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width*/

    visibility: "Windowed" // "FullScreen" //
    title: "QML-ListView-Example"

    color:"lightgray"

    TabBar {// Нажмите кнопку соответствующего переключения
        id: bar
        //color:"lightgray"
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        //height: 30
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
        TabButton {
            text: qsTr("Third")
        }
        TabButton {
            text: qsTr("Fourth")
        }
    }


    StackLayout {// Mayout Mayout
        anchors {
            top: bar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        currentIndex: bar.currentIndex // Индекс текущего представления
        Rectangle {
            color: Common.Colors.mainBackgroundColor

            ColumnLayout {
                anchors.centerIn: parent

                RadioButton {
                    height: 20 * Common.Consts.xCoord
                    width: 300 * Common.Consts.yCoord
                    text: "RadioButton"

                    Layout.alignment: Qt.AlignHCenter
                }

                RadioButton {
                    height: 20 * Common.Consts.xCoord
                    width: 300 * Common.Consts.yCoord
                    text: "RadioButton"
                    Layout.alignment: Qt.AlignHCenter
                }

                RadioButton {
                    height: 20 * Common.Consts.xCoord
                    width: 300 * Common.Consts.yCoord
                    text: "RadioButton"
                    Layout.alignment: Qt.AlignHCenter
                    enabled: false
                }
            }
        }
        Rectangle {
            color: Common.Colors.mainBackgroundColor
            ColumnLayout {
                anchors.centerIn: parent

                CheckBox {
                    height: 20 * Common.Consts.xCoord
                    width: 120 * Common.Consts.yCoord
                    text: "CheckBox"

                    Layout.alignment: Qt.AlignHCenter

                    //enabled: false
                }

                CheckBox {
                    height: 20 * Common.Consts.xCoord
                    width: 120 * Common.Consts.yCoord
                    text: "CheckBox"

                    Layout.alignment: Qt.AlignHCenter

                    //enabled: false
                }
                CheckBox {
                    height: 20 * Common.Consts.xCoord
                    width: 120 * Common.Consts.yCoord
                    text: "CheckBox"

                    Layout.alignment: Qt.AlignHCenter

                    enabled: false
                }
            }
        }
        Rectangle {
            color: Common.Colors.mainBackgroundColor
            ScrollView {
                id: scroll

                anchors.centerIn: parent
                height: 200 * Common.Consts.xCoord
                width: 400 * Common.Consts.yCoord

                TextArea  {
                    text: "TextArea"
                }

                ScrollBar.vertical: ScrollBar {
                    id: ver
                    policy: ScrollBar.AsNeeded

                    height: parent.height
                    anchors.right: parent.right
                }

                ScrollBar.horizontal: ScrollBar {
                    policy: ScrollBar.AsNeeded

                    width: ver.visible ? parent.width - ver.width : parent.width
                    anchors.bottom: parent.bottom
                }
            }
        }

        Rectangle {
            color: Common.Colors.mainBackgroundColor

            GridLayout {
                id: grid

                anchors {
                    centerIn: parent
                    leftMargin: 20 * Common.Consts.xCoord
                    rightMargin: 20 * Common.Consts.xCoord
                    topMargin: 20 * Common.Consts.yCoord
                    bottomMargin: 20 * Common.Consts.yCoord
                }

                columns: 4
                rows: 3

                RoundButton {
                    text: "RoundButton"
                    height: 20 * Common.Consts.xCoord
                    width: 120 * Common.Consts.yCoord

                    Layout.row: 0
                    Layout.column: 0
                    Layout.alignment: Qt.AlignHCenter

                    onClicked: {
                        Qt.callLater(Qt.quit);
                    }
                }

                TextField {
                    height: 20 * Common.Consts.xCoord
                    width: 100 * Common.Consts.yCoord

                    text: "TextField"
                    Layout.row: 0
                    Layout.column: 1
                    Layout.alignment: Qt.AlignHCenter
                }

                Label {
                    height: 20 * Common.Consts.xCoord
                    width: 100 * Common.Consts.yCoord

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    text: "Label"
                    Layout.row: 0
                    Layout.column: 2
                    Layout.alignment: Qt.AlignHCenter
                }

                ComboBox {
                    height: 20 * Common.Consts.xCoord
                    width: 100 * Common.Consts.yCoord

                    model: [ "1", "2", "3" ]

                    Layout.row: 0
                    Layout.column: 3
                    Layout.alignment: Qt.AlignHCenter
                }

                Switch {
                    height: 40 * Common.Consts.xCoord
                    width: 100 * Common.Consts.yCoord
                    text: "Switch"
                    Layout.row: 1
                    Layout.column: 0
                    Layout.alignment: Qt.AlignHCenter
                    //enabled: false
                }

                ProgressBar {
                    //text: "ProgressBar"
                    value: 78
                    Layout.row: 4
                    Layout.column: 0
                    Layout.columnSpan: 4
                    width: 700 * Common.Consts.xCoord
                    height: 30 * Common.Consts.yCoord
                }
            }
        }
    }
}