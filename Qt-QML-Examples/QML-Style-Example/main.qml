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

    GridLayout {
        id: grid

        anchors {
            fill: parent
            leftMargin: 20 * Common.Consts.xCoord
            rightMargin: 20 * Common.Consts.xCoord
            topMargin: 20 * Common.Consts.yCoord
            bottomMargin: 20 * Common.Consts.yCoord
        }

        columns: 5
        rows: 5

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

        CheckBox {
            height: 20 * Common.Consts.xCoord
            width: 120 * Common.Consts.yCoord
            text: "CheckBox"

            Layout.row: 0
            Layout.column: 4
            Layout.alignment: Qt.AlignHCenter

            //enabled: false
        }

        RadioButton {
            height: 20 * Common.Consts.xCoord
            width: 300 * Common.Consts.yCoord
            text: "RadioButton"
            Layout.row: 1
            Layout.column: 0
            Layout.alignment: Qt.AlignHCenter
        }

        Switch {
            height: 40 * Common.Consts.xCoord
            width: 200 * Common.Consts.yCoord
            text: "Switch"
            Layout.row: 1
            Layout.column: 1
            Layout.alignment: Qt.AlignHCenter
            //enabled: false
        }

        GroupBox {
            title: "GroupBox"
            Layout.row: 2
            Layout.column: 0
            Layout.columnSpan: 5
            Layout.rowSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true

            TextArea {
                text: "TextArea"
                anchors.fill: parent
                anchors.margins: 50
                //height: 400 * Common.Consts.xCoord
            }
        }
    }
}
