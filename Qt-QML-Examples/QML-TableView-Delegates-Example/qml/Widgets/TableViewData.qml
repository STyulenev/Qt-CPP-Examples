import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

//import Delegates 1.0 as Delegates

TableView {
    id: tableView

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.fill: parent

    clip: true

    property bool hasHorizontalHeader: true
    property bool hasVerticalHeader: true
    property bool hasHorizontalSeparator: true
    property var widthsColumn: model.columnWidths

    topMargin: hasHorizontalHeader ? 35 : 0
    leftMargin: hasVerticalHeader ? 35 : 0

    Row {
        id: columnsHeader
        y: tableView.contentY
        z: 2

        Repeater {
            model: tableView.columns > 0 ? tableView.columns : 1
            Label {
                width: tableView.width * widthsColumn[modelData]
                visible: tableView.hasHorizontalHeader
                height: 35
                text: tableView.model.headerData(modelData, Qt.Horizontal, Qt.DisplayRole)
                color: '#aaaaaa'
                font.pixelSize: 15
                padding: 10
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#333333"
                }
            }
        }
    }

    Column {
        id: rowsHeader
        x: tableView.contentX
        z: 2
        Repeater {
            model: tableView.rows > 0 ? tableView.rows : 1
            Label {
                width: 35
                height: 35
                text: tableView.model.headerData(modelData, Qt.Vertical, Qt.DisplayRole)
                color: '#aaaaaa'
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#333333"
                }
            }
        }
    }

    delegate: Rectangle {
        id: delegate

        implicitWidth: (tableView.width - 35) * widthsColumn[column]
        implicitHeight: 35
        clip: true

        Loader {
            anchors.centerIn: parent
            asynchronous: true
            visible: status == Loader.Ready
            source: switch (model.column) {
                    case 0: return "../Delegates/LabelDelegate.qml"
                    case 1: return "../Delegates/ImageDelegate.qml"
                    case 2: return "../Delegates/TextInputDelegate.qml"
                    case 3: return "../Delegates/CheckBoxDelegate.qml"
                    }
        }

        Rectangle {
            id: separator
            z: 2
            anchors {
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            height: 1
            visible: hasHorizontalSeparator
            color: "black"
        }
    }

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AsNeeded
    }

    ScrollBar.horizontal: ScrollBar {
        policy: ScrollBar.AsNeeded
    }
}
