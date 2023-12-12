pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Theme 1.0 as Theme

QtObject {
    // Флаг смены темы
    property string theme: "blue"

    // Список существующих тем
    readonly property var blueTheme: Theme.BlueTheme { }
    readonly property var purpleTheme: Theme.PurpleTheme { }
    readonly property var redTheme: Theme.RedTheme { }

    // Текущая тема
    readonly property Theme.AbstractTheme currentTheme: {
        switch(theme) {
        case "blue":
            return blueTheme;
        case "purple":
            return purpleTheme;
        case "red":
            return redTheme;
        default:
            return blueTheme;
        }
    }

    // Постоянные цвета
    //readonly property QtObject permanentСolors: QtObject {
    readonly property color mainBackgroundColor: "#000000"

    readonly property color inactiveControlColor: "#313031"
    readonly property color inactivePressedControlColor: Qt.lighter(inactiveControlColor, 1.3)
    readonly property color activeControlColor: "#63CBC6"
    readonly property color activePressedControlColor: Qt.lighter(activeControlColor, 1.3)

    readonly property color textColor: "#FFFFFF"
    readonly property color hintTextColor: "#CECECE"

    readonly property color greyColor: "#808080"

    readonly property color textFieldTextColor: "#000000"
    readonly property color textFieldBackgroundColor: "#ffffff"
    readonly property color textFieldCursorColor: "#000000"
    readonly property color textFieldTealCursorColor: "#67c8c6"
    readonly property color textFieldSelectionColor: "#0096c9"
    readonly property color textFieldDisabledColor: "#808080"
    readonly property color textFieldDisabledBackgroundColor: "#8e8c8e"
    readonly property color textFieldFocusedColor: "#039ed3"
    readonly property color textAlertMessage: "#ff0000"
    //}
}
