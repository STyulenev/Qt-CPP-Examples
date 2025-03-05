import QtQuick 2.15
import QtQuick.Templates 2.15 as Template

Template.MenuItem {
    id: control

    width: labelRow.implicitWidth + leftPadding + rightPadding
    implicitHeight: background.implicitHeight

    topPadding: 4
    bottomPadding: 4
    leftPadding: 4
    rightPadding: 4

    contentItem: Row {
        id: labelRow

        x: control.leftPadding

        // Icon, Label, ...

        Text {
            id: mainText

            anchors.verticalCenter: parent.verticalCenter

            width: mainText.implicitWidth

            visible: control.text
            text: control.text
            font: control.font
            elide: Text.ElideRight
        }
    }

    indicator: null

    background: Rectangle {
        id: bg

        x: control.leftPadding

        implicitWidth: control.width
        implicitHeight: 40

        width: control.parent.width - 2 * control.leftPadding
        height: control.height
        color: "transparent"
    }
}
