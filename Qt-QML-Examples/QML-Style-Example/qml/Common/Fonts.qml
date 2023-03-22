pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Common 1.0 as Common

QtObject {
    property FontLoader fontLoader: FontLoader {
        id: fontLoader
        source: "qrc:/fonts/Helvetica.ttf"
    }

    readonly property alias family: fontLoader.name
    readonly property int pixelSize: 14 * Common.Consts.fontSize

}
