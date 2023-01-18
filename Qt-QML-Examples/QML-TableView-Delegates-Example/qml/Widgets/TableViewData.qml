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

    rowSpacing: 8
    clip: true

    property bool hasHorizontalHeader: true
    //property bool hasVerticalHeader: true
    property bool hasHorizontalSeparator: true
    property var widthsColumn: model.columnWidths

    topMargin: hasHorizontalHeader ? 35 : 0
    //leftMargin: hasVerticalHeader ? 30 : 0


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

    /*Column {
        id: rowsHeader
        x: tableView.contentX
        z: 2
        Repeater {
            model: tableView.rows > 0 ? tableView.rows : 1
            Label {
                width: 30
                height: 35//tableView.rowHeightProvider(modelData)
                text: tableView.headerData(modelData, Qt.Vertical)
                color: '#aaaaaa'
                font.pixelSize: 15
                padding: 10
                verticalAlignment: Text.AlignVCenter

                background: Rectangle {
                    color: "#333333"
                }
            }
        }
    }*/

    delegate: Rectangle {
        implicitWidth: tableView.width * widthsColumn[column]
        implicitHeight: 30

        clip: true

        Label {
            id: labelDelegate
            text: model.DisplayRole
            visible: model.column === 0
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: model.TextAlignmentRole

            ToolTip.text: model.ToolTipRole
            ToolTip.visible: model.ToolTipRole ? maLabelDelegate.containsMouse : false

            MouseArea {
                id: maLabelDelegate
                anchors.fill: parent
                hoverEnabled: true
            }
        }

        Image {
            id: iconDelegate
            visible: model.column === 1
            anchors.centerIn: parent
            source: model.DecorationRole

            ToolTip.text: model.ToolTipRole
            ToolTip.visible: model.ToolTipRole ? maIconDelegate.containsMouse : false

            MouseArea {
                id: maIconDelegate
                anchors.fill: parent
                hoverEnabled: true
            }
        }

        TextInput {
            id: lineEditDelegate
            anchors.centerIn: parent
            visible: model.column === 2
            text: model.DisplayRole

            onTextEdited:  {
                model.EditRole = text
            }

            ToolTip.text: model.ToolTipRole
            ToolTip.visible: model.ToolTipRole ? maLineEditDelegate.containsMouse : false

            MouseArea {
                id: maLineEditDelegate
                anchors.fill: parent
                hoverEnabled: true
            }
        }

        CheckBox {
            id: checkDelegate
            visible: model.column === 3
            checked: model.CheckStateRole ? Qt.Checked : Qt.Unchecked
            anchors.centerIn: parent

            onClicked: {
                model.CheckStateRole = checked ? Qt.Checked : Qt.Unchecked
            }

            ToolTip.text: model.ToolTipRole
            ToolTip.visible: model.ToolTipRole ? maCheckDelegate.containsMouse : false

            MouseArea {
                id: maCheckDelegate
                anchors.fill: parent
                hoverEnabled: true
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
