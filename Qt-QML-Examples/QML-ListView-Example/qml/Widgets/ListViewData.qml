import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ListView {
    id: listView

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.fill: parent

    spacing: 5
    clip: true

    property var listViewColumnsWidths: listView.model.columnWidths

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AlwaysOff
    }

    ScrollBar.horizontal: ScrollBar {
        policy: ScrollBar.AlwaysOff
    }

    delegate: Rectangle {
        id: delegate
        width: listView.width
        height: 180

        border.color: "black"
        border.width: 2

        GridLayout {
            id: grid
            opacity: model.StatusRole ? 0.4 : 1;

            anchors {
                fill: parent
                leftMargin: 2
                topMargin: 2
                rightMargin: 10
                bottomMargin: 2
            }

            rows: 5
            columns: 3

            Rectangle {
                id: imageDelegate
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height - (delegate.border.width * 2 + grid.anchors.topMargin + grid.anchors.bottomMargin)
                Layout.columnSpan: 1
                Layout.rowSpan: 5
                Layout.row: 0
                Layout.column: 0

                Image {
                    id: icon
                    source: model.DecorationRole

                    anchors {
                        centerIn: parent
                        margins: 10
                    }
                }
            }

            Label {
                id: nameDelegate
                text: model.DisplayRole

                Layout.preferredWidth: (parent.width / parent.columns) * 2
                Layout.preferredHeight: parent.height / parent.rows
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.row: 0
                Layout.column: 1

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Qt.AlignHCenter

                font.pixelSize: 22
                font.family: "Verdana"
                font.weight: Font.Bold
            }

            Text {
                id: descriptionDelegate
                text: model.DescriptionRole

                Layout.preferredWidth: (parent.width / parent.columns) * 2
                Layout.preferredHeight: (parent.height / parent.rows) * 4
                Layout.columnSpan: 2
                Layout.rowSpan: 4
                Layout.row: 1
                Layout.column: 1

                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignLeft
                horizontalAlignment: Qt.AlignLeft

                font.pixelSize: 12
                font.family: "Verdana"
                font.weight: Font.Bold
            }
        }
    }
}
