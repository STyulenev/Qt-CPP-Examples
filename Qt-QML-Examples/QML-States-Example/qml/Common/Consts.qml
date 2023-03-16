pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

QtObject {
    readonly property int screenWidth: 400
    readonly property int screenHeight: 600

    readonly property color brightMainBackgroundColor: "#C2F1EB"
    readonly property color darkMainBackgroundColor: "#6C13D0"

    readonly property color brightTitleBackgroundColor: "#A4E0FC"
    readonly property color darkTitleBackgroundColor: "#4416BB"

    readonly property color brightCellBackgroundColor: "#A4E8EC"
    readonly property color darkCellBackgroundColor: "#6C07F5"
}
