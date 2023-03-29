import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Common 1.0 as Common

ApplicationWindow {
    id: appWindow
    visible: true
    width: Common.Consts.screenWidth
    height: Common.Consts.screenHeight
    /*maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width*/

    visibility: "Windowed" // "FullScreen" //
    title: "QML-ListView-Example"

    /*RoundButton {
        id: button
        anchors.centerIn: parent
        text: "text"
        height: 20 * Common.Consts.xCoord
        width: 100 * Common.Consts.yCoord

        onClicked: {
            Qt.callLater(Qt.quit);
        }
    }*/

    /*ComboBox {
        anchors.centerIn: parent
        height: 20 * Common.Consts.xCoord
        width: 100 * Common.Consts.yCoord

        model: [ "1", "2", "3" ]
    }*/

    /*TextField {
        anchors.centerIn: parent
        height: 20 * Common.Consts.xCoord
        width: 100 * Common.Consts.yCoord

        text: "qwrqw"
    }*/

    /*Label {
        anchors.centerIn: parent
        height: 20 * Common.Consts.xCoord
        width: 100 * Common.Consts.yCoord

        text: "qwrqw"
    }*/

    TextArea {
        anchors.centerIn: parent
        height: 200 * Common.Consts.xCoord
        width: 500 * Common.Consts.yCoord

        text: "qwrqw"
    }
}
