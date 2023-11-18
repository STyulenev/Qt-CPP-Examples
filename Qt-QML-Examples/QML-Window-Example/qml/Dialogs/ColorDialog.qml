import QtQuick 2.15

import QtQuick.Dialogs as StandartDialogs

StandartDialogs.ColorDialog {
    id: colorDialog

    visible: false
    modality: Qt.WindowModal
    title: "Choose a color"

    onAccepted: {
        console.log("Accepted: " + colorDialog.selectedColor)
    }

    onRejected: {
        console.log("Rejected")
    }

    Component.onCompleted: {
        console.log("create ColorDialog ")
    }

    Component.onDestruction: {
        console.log("delete ColorDialog ")
    }
}
