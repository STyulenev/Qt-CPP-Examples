import QtQuick
import QtQuick.Controls 2.15

TableView {
    id: tableView

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.fill: parent
    anchors.margins: 24
    rowSpacing: 8
    clip: true

    property var horizontalHeaders
    property var columnWidths
    property var textAlignments

    property bool hasHorizontalHeader: true
    property bool hasHorizontalSeparator: true

    topMargin: hasHorizontalHeader ? 35 : 0

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
                width: tableView.width * tableView.columnWidths[modelData]
                visible: tableView.hasHorizontalHeader
                height: 35
                text: tableView.horizontalHeaders[modelData] ? tableView.horizontalHeaders[modelData] : ""
                color: '#aaaaaa'
                font.pixelSize: 15
                padding: 10
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: tableView.textAlignments[modelData]

                background: Rectangle {
                    color: "#333333"
                }
            }
        }
    }

    delegate: Item {
        implicitWidth: tableView.width * tableView.columnWidths[column]
        implicitHeight: 30

        Label {
            id: labelDelegate
            text: model.display
            anchors.centerIn: parent
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
}
