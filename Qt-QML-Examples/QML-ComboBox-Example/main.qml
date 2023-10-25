import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

// Import C ++ class
import ViewModels 0.1 as Models

import Components 1.0 as Components

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-ComboBox-Example")

    property QtObject currentView: Models.ComboBoxViews {}

    Components.ComboBox {
        id: comboBox
        anchors.centerIn: parent
        width: 150
        height: 30

        model: currentView.comboBoxViewModel
    }
}
