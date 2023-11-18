import QtQuick 2.15

import QtQuick.Dialogs as StandartDialogs

StandartDialogs.FontDialog {
    id: fontDialog

    title: "Please choose a font"
    currentFont: Qt.font({ family: "Arial", pointSize: 24, weight: Font.Normal })

    onAccepted: {
        console.log("You chose: " + fontDialog.currentFont)
    }

    onRejected: {
        console.log("Canceled")
    }
}
