import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.ProgressBar {
    id: progressBar
    to: 100.0
    from: 0.0
    padding: 2 * Common.Consts.xCoord

    background: Rectangle {
        anchors.fill: parent
        color: Common.Colors.textFieldBackgroundColor
        radius: 3 * Common.Consts.radialSize

        border {
            width: 2 * Common.Consts.radialSize
            color: Common.Colors.currentTheme.mainThemeColor
        }
    }

    contentItem: Item {
        implicitHeight: 30 * Common.Consts.yCoord

        anchors {
            fill: parent
            margins: 4 * Common.Consts.radialSize
        }

        Rectangle {
            z: 1
            width: progressBar.visualPosition * parent.width
            height: parent.height
            radius: 2 * Common.Consts.radialSize
            color: Common.Colors.currentTheme.mainThemeColor
        }

        Text {
            id: text
            z: 2
            text: qsTr("Loading %1 %").arg(progressBar.value)
            color: Common.Colors.mainBackgroundColor
            anchors.centerIn: parent

            font {
                family: Common.Fonts.family
                pixelSize:Common.Fonts.pixelSize
                bold: true
            }

            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.Wrap
        }
    }
}
