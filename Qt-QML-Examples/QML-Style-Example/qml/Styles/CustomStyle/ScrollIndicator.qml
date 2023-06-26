import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.ScrollIndicator {
    id: scrollIndicator
    active: true

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding)

    contentItem: Rectangle {
        id: slider
        radius: 4 * Common.Consts.radialSize
        color: Common.Colors.activeControlColor
        visible: scrollIndicator.size < 1.0

        states: [
            State {
                name: "vertical"
                when: scrollIndicator.orientation === Qt.Vertical
                PropertyChanges {
                    target: slider
                    implicitWidth: 10 * Common.Consts.xCoord
                    implicitHeight: 4 * Common.Consts.xCoord
                }
            },
            State {
                name: "horizontal"
                when: scrollIndicator.orientation === Qt.Horizontal
                PropertyChanges {
                    target: slider
                    implicitWidth: 4 * Common.Consts.xCoord
                    implicitHeight: 10 * Common.Consts.xCoord
                }
            }
        ]
    }
}
