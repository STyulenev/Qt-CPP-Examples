import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

CheckBox {
    id: checkDelegate

    visible: model.column === 3
    checked: model.CheckStateRole ? Qt.Checked : Qt.Unchecked
    anchors.centerIn: parent

    default property alias children: maCheckDelegate.data

    onClicked: {
        model.CheckStateRole = checked ? Qt.Checked : Qt.Unchecked
    }

    ToolTip.text: model.ToolTipRole
    ToolTip.visible: model.ToolTipRole ? maCheckDelegate.containsMouse : false

    MouseArea {
        id: maCheckDelegate
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.RightButton

        onClicked: {
            mouse.accepted = true
        }
    }
}
