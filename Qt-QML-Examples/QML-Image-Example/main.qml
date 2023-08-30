import QtQuick 2.15
import QtQml 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3

import MyWidgets 1.0 as MyWidgets

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Image-Example")

    RowLayout {
        anchors.centerIn: parent
        spacing: 20

        MyWidgets.ImageBox {
            height: 32
            width: 32
        }

        Image {
            width: 32
            height: 32
            source: "image://colors"
        }
    }
}
