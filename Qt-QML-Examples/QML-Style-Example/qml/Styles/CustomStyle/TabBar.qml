import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.TabBar {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            contentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + topPadding + bottomPadding)

    contentItem: ListView {
        model: control.contentModel
        currentIndex: control.currentIndex
        spacing: control.spacing
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.AutoFlickIfNeeded
        snapMode: ListView.SnapToItem
        highlightMoveDuration: 0
        highlightRangeMode: ListView.ApplyRange
        preferredHighlightBegin: 40
        preferredHighlightEnd: width - 40
    }

    background: Rectangle {
        color: Common.Colors.mainBackgroundColor

        Rectangle {
            color: Common.Colors.mainThemeColor
            width: parent.width
            height: 2 * Common.Consts.yCoord
            anchors.bottom: parent.bottom
        }
    }
}
