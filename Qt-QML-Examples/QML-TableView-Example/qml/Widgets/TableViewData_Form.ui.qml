import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

TableView {
    id: tableView

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.fill: parent
    anchors.margins: 24

    //columnSpacing: 8
    rowSpacing: 8
    clip: true

    model: currentModel

    property var columnssss: currentModel.columnWidths

    topMargin: true ? 35 : 0

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AsNeeded
    }

    ScrollBar.horizontal: ScrollBar {
        policy: ScrollBar.AsNeeded
    }

    Row {
        id: columnsHeader
        y: tableView.contentY
        z: 2

        Repeater {
            model: tableView.columns > 0 ? tableView.columns : 1
            Label {
                width: tableView.width * columnssss[modelData]
                visible: appWindow.hasHeader
                height: 35
                text: currentModel.horizontalHeaders[modelData] ? currentModel.horizontalHeaders[modelData] : ""
                color: '#aaaaaa'
                font.pixelSize: 15
                padding: 10
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: currentModel.textAlignments[modelData]

                background: Rectangle {
                    color: "#333333"
                }
            }
        }
    }

    delegate: Rectangle {
        implicitWidth: tableView.width * columnssss[column]
        implicitHeight: 30

        Label {
            id: labelDelegate
            text: model.DisplayRole
            visible: model.column !== 3
            anchors.centerIn: parent
        }

        CheckBox {
            id: checkDelegate
            visible: model.column === 3
            checkState: model.CheckStateRole ? Qt.Checked : Qt.Unchecked
            anchors.centerIn: parent

            Connections {
                target: checkDelegate

                function onCheckedChanged() {
                    model.CheckStateRole = checkState
                }
            }
        }

        // separator
        Rectangle {
            z: 2
            anchors {
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            height: 1
            visible: true
            color: "black"
        }
    }
}
