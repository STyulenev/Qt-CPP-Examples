import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

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
        acceptedButtons: Qt.RightButton

        onClicked: {
            mouse.accepted = true
        }
    }
}
