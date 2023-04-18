pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

QtObject {
    readonly property int mockupScreenWidth: 800
    readonly property int mockupScreenHeight: 600

    readonly property int screenWidth: 1200 //Screen.width
    readonly property int screenHeight: 1000 //Screen.height

    readonly property real xCoord: screenWidth / mockupScreenWidth
    readonly property real yCoord: screenHeight / mockupScreenHeight
    readonly property real radialSize: Math.min(xCoord, yCoord)
    readonly property real fontSize: Math.min(xCoord, yCoord)
}
