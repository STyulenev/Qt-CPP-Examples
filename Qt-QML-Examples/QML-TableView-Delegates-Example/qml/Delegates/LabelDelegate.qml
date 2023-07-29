import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

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
