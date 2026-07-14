pragma Singleton

import QtQuick 2.15
import QtQuick.Window 2.2

QtObject {
    id: consts

    property int mockupScreenWidth: 1200
    property int mockupScreenHeight: 800

    readonly property int screenWidth: Screen.width
    readonly property int screenHeight: Screen.height

    readonly property real xCoord: mockupScreenWidth / screenWidth
    readonly property real yCoord:  mockupScreenHeight / screenHeight

    // ...
} // QtObject
