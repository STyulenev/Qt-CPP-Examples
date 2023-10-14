import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

// Import C ++ class
import ViewModels 0.1 as Models

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-ComboBox-Example")

    property QtObject currentView: Models.ComboBoxViews {}

    ComboBox {
        anchors.centerIn: parent
        id: control
        model: currentView.comboBoxViewModel
        delegate: ItemDelegate {
            width: control.width
            contentItem: Text {
                text: modelData
                font: control.font
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
