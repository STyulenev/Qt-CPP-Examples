import QtQuick 2.15
import QtQml 2.15
import QtQuick.Window 2.15

import QIconImage 1.0 as Models

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Image-Example")

    Models.QIconImage {
            anchors.centerIn: parent
           height: 160
            //rightAligned: index % 2 != 0
           width: 160
        }

   /*Image {
        width: 81
        height: 81
        anchors.centerIn: parent
        source: "image://colors"
    }*/
}
