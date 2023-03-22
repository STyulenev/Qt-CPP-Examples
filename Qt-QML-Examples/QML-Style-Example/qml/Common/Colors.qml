pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

QtObject {
    readonly property color mainBackgroundColor: "#000000"

    readonly property color inactiveControlColor: "#313031"
    readonly property color inactivePressedControlColor: Qt.lighter(inactiveControlColor, 1.3)
    readonly property color activeControlColor: "#63CBC6"
    readonly property color activePressedControlColor: Qt.lighter(activeControlColor, 1.3)

    readonly property color textColor: "#FFFFFF"
    readonly property color hintTextColor: "#CECECE"
}
