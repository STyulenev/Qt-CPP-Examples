import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root

    width: 620
    height: 180

    property string displayRole: ""
    property string decorationRole: ""
    property string toolTipRole: ""
    property string descriptionRole: ""
    property bool statusRole: false

    border.color: "black"
    border.width: 2

    GridLayout {
        id: grid
        opacity: root.statusRole ? 0.4 : 1

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
            id: image
            Layout.preferredWidth: parent.width / parent.columns
            Layout.preferredHeight: parent.height - (root.border.width * 2 + grid.anchors.topMargin + grid.anchors.bottomMargin)
            Layout.columnSpan: 1
            Layout.rowSpan: 5
            Layout.row: 0
            Layout.column: 0

            Image {
                id: icon
                source: root.decorationRole

                anchors {
                    centerIn: parent
                    margins: 10
                }
            }
        }

        Label {
            id: name
            text: root.displayRole

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
            id: description
            text: root.descriptionRole

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
