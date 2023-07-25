import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

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
